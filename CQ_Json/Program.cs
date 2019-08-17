using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.IO;

namespace CQ_Json
{
    class Program
    {
        static DirectoryInfo CQ_DIR;
        static CQJson app = new CQJson();
        static void Main(string[] args)
        {
            DirectoryInfo srcDir, diDir;
            {
                var str = System.Diagnostics.Process.GetCurrentProcess().MainModule.ModuleName;
                var help = "从源文件中提取插件信息,在指定目录生成JSON.\n\n" +
                   str + " <源文件目录> <生成目录> (酷Q目录)\n\n" +
                   "此命令将扫描 源文件目录 中所有CPP文件,\n" +
                   "并提取包含信息内容的宏,用于生成JSON,\n" +
                   "随后将app.dll以及app.json复制至<酷Q/dev/APP_ID/>目录,\n" +
                   "请查看CQ_APP项目相关源文件了解更多相关内容";
                if (args.Length == 0)
                {
                    Console.Write(help); return;
                }
                else if (args[0] == "/?")
                {
                    Console.Write(help); return;
                }

                srcDir = new DirectoryInfo(args[0]);
                if (!srcDir.Exists)
                {
                    Console.Write("源文件目录不存在."); return;
                }
                diDir = new DirectoryInfo(args[2]);
                if (!diDir.Exists)
                {
                    Console.Write("生成目录不存在."); return;
                }
            }

            Console.WriteLine(srcDir);
            var cpps = 遍历目录(srcDir, "*.cpp");
            foreach (var file in cpps)
            {
                try
                {
                    FileStream fs = new FileStream(file.FullName, FileMode.Open);
                    StreamReader sr = new StreamReader(fs);
                    string s = sr.ReadToEnd();
                    sr.Close();
                    fs.Close();
                    解析文件(s);
                }
                catch
                {
                    Console.WriteLine("文件打开失败:" + file.FullName);
                }
            }
        }

        private static List<FileInfo> 遍历目录(DirectoryInfo srcDir, string v)
        {
            var al = new List<FileInfo>();
            var files = srcDir.GetFiles(v);
            al.AddRange(files);

            var dirs = srcDir.GetDirectories();

            foreach (var dir in dirs)
            {
                var list = 遍历目录(dir, v);
                al.AddRange(list);
            }

            return al;
        }

        static int linePos = 0;
        static string[] lines = null;
        static string line = null;
        private static void 解析文件(string cpp)
        {
            lines = cpp.Split('\n');
            for (linePos = 0; linePos < lines.Length; linePos++)
            {
                line = lines[linePos];
                //基础信息
                if (line.StartsWith("#define APP_name ")) { app.name = 取引号文本_贪婪(line); }
                else if (line.StartsWith("#define APP_author ")) { app.author = 取引号文本_贪婪(line); }
                else if (line.StartsWith("#define APP_description ")) { app.description = 取引号文本_贪婪(line); }
                else if (line.StartsWith("#define APP_version ")) { app.version = 取引号文本_贪婪(line); }
                else if (line.StartsWith("#define APP_version_id ")) {
                    line = line.Substring("#define APP_version_id ".Length).Trim();
                    try {
                        app.version_id = int.Parse(line);
                        lines[linePos] = "#define APP_version_id " + app.version_id + 1;
                    } catch (Exception) { }
                }
                else if (line.StartsWith("#define CQ_DIR ")) {CQ_DIR = new DirectoryInfo(取引号文本_贪婪(line));}

                //事件
                else if (line.StartsWith("EVE_Startup")) { addEVE(1001); }
                else if (line.StartsWith("EVE_Exit")) { addEVE(1002); }
                else if (line.StartsWith("EVE_Enable")) { addEVE(1003); }
                else if (line.StartsWith("EVE_Disable")) { addEVE(1004); }
                else if (line.StartsWith("EVE_PrivateMsg")) { addEVE(21); }
                else if (line.StartsWith("EVE_GroupMsg")) { addEVE(2); }
                else if (line.StartsWith("EVE_DiscussMsg")) { addEVE(4); }
                else if (line.StartsWith("EVE_System_GroupAdmin")) { addEVE(101); }
                else if (line.StartsWith("EVE_Friend_Add")) { addEVE(201); }
                else if (line.StartsWith("EVE_Request_AddFriend")) { addEVE(301); }
                else if (line.StartsWith("EVE_Request_AddGroup")) { addEVE(302); }
                else if (line.StartsWith("EVE_GroupUpload")) { addEVE(11); }
                else if (line.StartsWith("EVE_System_GroupMemberDecrease")) { addEVE(102); }
                else if (line.StartsWith("EVE_System_GroupMemberIncrease")) { addEVE(103); }
                //菜单和悬浮窗
                else if (line.StartsWith("EVE_Menu")) { addMenu(); }
                else if (line.StartsWith("EVE_Status")) { addStatus(); }
                //权限
                else if (line.StartsWith("#define APP_auth_"))
                {
                    var authstr = 取文本中间(line, "APP_auth_", " ");
                    var authint = int.Parse(authstr);
                    app.auth.Add(authint);
                }
            }
        }

        private static void addEVE(int Type)
        {
            var function = 取文本中间(line, "(", ")");
            var name = function;
            var priority = 30000;
            var max = 20;
            var reg = new CQregex();
            while ((line = lines[++linePos]).IndexOf("{") < 0 && --max > 0)
            {
                if (line.StartsWith("//name:"))
                {
                    name = line.Substring("//name:".Length);
                }
                else if (line.StartsWith("//priority:"))
                {
                    try { priority = int.Parse(line.Substring("//priority:".Length)); } catch (Exception) { }
                }
                else if (line.StartsWith("//regex-key:"))
                {
                    var key = line.Substring("//regex-key:".Length);
                    reg.key.Add(key);
                }
                else if (line.StartsWith("//regex-expression:"))
                {
                    var expression = line.Substring("//regex-expression:".Length);
                    reg.expression.Add(expression);
                }
            }
            CQevent eve= new CQevent(type: Type, name: name, function: function, priority: priority);
            if (reg.expression.Count > 0)
                eve.regex = reg;
            
            app._event.Add(eve);
        }
        private static void addMenu()
        {
            var function = 取文本中间(line, "(", ")");
            var name = function;
            var max = 10;
            while ((line = lines[++linePos]).IndexOf("{") < 0 && --max > 0)
            {
                if (line.StartsWith("//name:"))
                {
                    name = line.Substring("//name:".Length);
                }
              
            }
            app.menu.Add(new CQmenu(name: name, function: function));
            ;
        }
        private static void addStatus()
        {
            var function = 取文本中间(line, "(", ")");
            var name = function;
            var title = "自制悬浮窗";
            var period = 1000;

            var max = 10;
            while ((line = lines[++linePos]).IndexOf("{") < 0 && --max > 0)
            {
                if (line.StartsWith("//name:"))
                {
                    name = line.Substring("//name:".Length);
                }
                else if (line.StartsWith("//title:"))
                {
                    title = line.Substring("//title:".Length);
                }
                else if (line.StartsWith("//period:"))
                {
                    try { period = int.Parse(line.Substring("//period:".Length)); } catch (Exception) { }
                }
            }
            app.status.Add(new CQstatus(name: name, function: function, period: period, title: title));
        }
        private static string 取文本中间(string text, string st, string end)
        {
            var stint = text.IndexOf(st);
            if (stint == -1) return "";
            stint += st.Length;
            var endint = text.IndexOf(end, stint);
            if (endint == -1) return "";
            return text.Substring(stint, endint - stint);
        }
        private static string 取引号文本_贪婪(string text)
        {
            var start = text.IndexOf('"');
            var end = text.LastIndexOf('"');
            var newstr = text.Substring(start, end - start);
            return newstr;
        }
        public class CQJson
        {

            public string name = "酷Q样例应用";
            public string version = "1.0.0";
            public int version_id = 1;
            public string author = "Example";
            public string description = "酷Q样例应用(V9应用机制)";
            [JsonProperty(PropertyName = "event")]
            public List<CQevent> _event = new List<CQevent>();
            public List<CQmenu> menu = new List<CQmenu>();
            public List<CQstatus> status = new List<CQstatus>();
            public List<int> auth = new List<int>();

            public int ret = 1;
            public int apiver = 9;

            public CQJson()
            {
            }

            public CQJson(int version_id, string name, string version, string author, string description)
            {
                this.version_id = version_id;
                this.name = name;
                this.version = version;
                this.author = author;
                this.description = description;
            }

            public void setid()
            {
                for (int i = 1; i <= _event.Count; i++)
                {
                    _event[i].id = i;
                }
                for (int i = 1; i <= status.Count; i++)
                {
                    status[i].id = i;
                }
            }
        }
        public class CQmenu
        {
            public string name;
            public string function;

            public CQmenu()
            {
            }

            public CQmenu(string name, string function)
            {
                this.name = name;
                this.function = function;
            }
        }
        public class CQevent
        {
            public int id;
            public int type;
            public string name;
            public string function;
            public int priority;
            [JsonProperty(NullValueHandling = NullValueHandling.Ignore)]
            public CQregex regex;

            public CQevent()
            {
            }

            public CQevent(int type, string name, string function, int priority)
            {
                this.type = type;
                this.name = name;
                this.function = function;
                this.priority = priority;
            }
        }
        public class CQregex
        {
            public List<string> key = new List<string>();
            public List<string> expression = new List<string>();
        }
        public class CQstatus
        {
            public int id;
            public string name;
            public string title;
            public string function;
            public int period;

            public CQstatus(string name, string title, string function, int period)
            {
                this.name = name;
                this.title = title;
                this.function = function;
                this.period = period;
            }
        }

        //测试用的类
        class Test
        {
            static void Main(string[] args)
            {
                CQJson j = new CQJson(1, "nnnn", "1.0.0", "tatamis", "yijuhua");
                j.auth.Add(1);
                j.auth.Add(2);
                j.auth.Add(3);
                j.auth.Add(4);
                j.auth.Add(5);

                j._event.Add(new CQevent(1001, "mmm", "fun1", 30000));
                j._event.Add(new CQevent(1002, "mmm", "fun2", 30000));

                CQregex r = new CQregex();
                r.key.Add("QQ");
                r.key.Add("action");
                r.expression.Add("^(?<action>\\S{1,4}?)\\s*(?<qq>\\d{5,10})\\s*?$");

                j._event[1].regex = r;

                j.menu.Add(new CQmenu("menu1", "fun5"));
                j.menu.Add(new CQmenu("menu2", "fun6"));

                string output = JsonConvert.SerializeObject(j);


                Console.WriteLine(output);
                Console.ReadLine();

            }
        }
    }
}