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
        static string line = null;
        private static void 解析文件(string cpp)
        {
            var lines = cpp.Split('\n');
            for (linePos = 0; linePos < lines.Length; linePos++)
            {
                line = lines[linePos];
                //基础信息
                if (line.StartsWith("#define APP_name ")) { app.name = 取引号文本_贪婪(line); }
                else if (line.StartsWith("#define APP_author ")) { app.author = 取引号文本_贪婪(line); }
                else if (line.StartsWith("#define APP_description ")) { app.description = 取引号文本_贪婪(line); }
                else if (line.StartsWith("#define APP_version ")) { app.version = 取引号文本_贪婪(line); }
                else if (line.StartsWith("#define APP_version_id ")) { }
                else if (line.StartsWith("#define CQ_DIR ")) {CQ_DIR = new DirectoryInfo(取引号文本_贪婪(line));}

                //事件
                else if (line.StartsWith("EVE_Startup")) { }
                else if (line.StartsWith("EVE_Exit")) { }
                else if (line.StartsWith("EVE_Enable")) { }
                else if (line.StartsWith("EVE_Disable")) { }
                else if (line.StartsWith("EVE_PrivateMsg")) { }
                else if (line.StartsWith("EVE_GroupMsg")) { }
                else if (line.StartsWith("EVE_DiscussMsg")) { }
                else if (line.StartsWith("EVE_System_GroupAdmin")) { }
                else if (line.StartsWith("EVE_Friend_Add")) { }
                else if (line.StartsWith("EVE_Request_AddFriend")) { }
                else if (line.StartsWith("EVE_Request_AddGroup")) { }
                else if (line.StartsWith("EVE_GroupUpload")) { }
                else if (line.StartsWith("EVE_System_GroupMemberDecrease")) { }
                else if (line.StartsWith("EVE_System_GroupMemberIncrease")) { }

                //菜单和悬浮窗
                else if (line.StartsWith("EVE_Menu")) { }
                else if (line.StartsWith("EVE_Status")) { }

                //权限
                else if (line.StartsWith("#define APP_auth_"))
                {
                    var authstr = 取文本中间(line, "APP_auth_", " ");
                    var authint = int.Parse(authstr);
                    app.auth.Add(authint);
                }
            }
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

            public string name;
            public string version;
            public int version_id;
            public string author;
            public string description;
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
            public List<string> key;
            public List<string> expression;
        }
        public class CQstatus
        {
            public int id;
            public string name;
            public string title;
            public string function;
            public int period;

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

                j.menu.Add(new CQmenu("menu1", "fun5"));
                j.menu.Add(new CQmenu("menu2", "fun6"));

                string output = JsonConvert.SerializeObject(j);


                Console.WriteLine(output);
            }
        }
    }
}