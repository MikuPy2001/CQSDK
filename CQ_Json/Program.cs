using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace CQ_Json
{
    class Program
    {
        //酷Q应用的根目录
        static string CQ_DIR;
        //Json对象
        static CQJson app = new CQJson();
        static void Main(string[] args)
        {
            string srcDir, //源文件目录
                outPutDir, //生成目录
                appJsonFile;//json生成路径
            //帮助
            {
                var str = System.Diagnostics.Process.GetCurrentProcess().MainModule.ModuleName;
                var help = "从源文件中提取插件信息,在指定目录生成JSON.\n\n" +
                   str + " <源文件目录> <生成目录> (酷Q目录)\n\n" +
                   "此命令将扫描 源文件目录 中所有CPP文件,\n" +
                   "并提取包含信息内容的宏,用于生成JSON,\n" +
                   "随后将app.dll以及app.json复制至<酷Q/dev/APP_ID/>目录,\n" +
                   "请查看CQ_APP项目相关源文件了解更多相关内容";
                if (args.Length == 0
                    || args[0] == "/?"
                    || args[0] == "?"
                    || args[0] == "help"
                    )
                { Console.WriteLine(help); return; }
            }
            //参数检查
            {
                Console.Write("(1)收到参数如下:");
                foreach (var s in args)
                {
                    Console.Write(s);
                    Console.Write("; ");
                }
                Console.WriteLine();

                if (args.Length > 0)
                {
                    if (Directory.Exists(args[0])) { srcDir = Path.GetDirectoryName(args[0]); }
                    else { Console.WriteLine("源文件目录不存在."); return; }
                }
                else { Console.WriteLine("未指定源文件目录."); return; }

                if (args.Length > 1)
                {
                    if (!Directory.Exists(args[1]))
                    {
                        try { Directory.CreateDirectory(args[1]); }
                        catch { Console.WriteLine("生成目录不存在且无法生成."); return; }
                    }
                    outPutDir = Path.GetDirectoryName(args[1]);
                    appJsonFile = Path.Combine(outPutDir, @"app.json");
                }
                else { Console.WriteLine("未指定生成文件目录."); return; }

                if (args.Length > 2) { CQ_DIR = Path.GetDirectoryName(args[2]); }
            }
            //解析文件
            try
            {
                //删除
                File.Delete(appJsonFile);

                StreamWriter outw = new StreamWriter(
                new FileStream(appJsonFile, FileMode.Create)
                , Encoding.UTF8);


                //开始遍历
                //Console.WriteLine("源文件目录" + srcDir);
                var cpps = 遍历目录(new DirectoryInfo(srcDir), "*.cpp");
                cpps.AddRange(遍历目录(new DirectoryInfo(srcDir), "*.h"));
                foreach (var file in cpps)
                {
                    try
                    {
                        StreamReader sr = new StreamReader(
                            new FileStream(file.FullName, FileMode.Open)
                            , Encoding.Default);
                        string s = sr.ReadToEnd();
                        sr.Close();
                        解析文件(s);
                        //todo; 保存修改的文件
                    }
                    catch
                    {
                        Console.WriteLine("源文件读入失败:" + file.FullName); return;
                    }
                }
                outw.Write(JsonConvert.SerializeObject(app));
                outw.Close();
                Console.WriteLine("酷QJSON构建成功.");
            }
            catch { Console.WriteLine("app.json无法写出,文件是否被占用:" + appJsonFile); return; }

            //把文件复制到酷Q目录
            if (CQ_DIR != null)
            {
                if (APP_ID != "")
                {
                    Console.WriteLine("应用ID为:" + APP_ID);
                    if (Directory.Exists(CQ_DIR))
                    {
                        string CQ_DEBDIR = Path.Combine(new string[] { CQ_DIR, @"dev", APP_ID });
                        string CQ_DLL = Path.Combine(new string[] { CQ_DEBDIR, @"app.dll" });
                        string CQ_JSON = Path.Combine(new string[] { CQ_DEBDIR, @"app.json" });

                        //检查目录是否存在
                        if (!Directory.Exists(CQ_DEBDIR))
                        {
                            try { Console.WriteLine("酷Q应用目录创建:" + Directory.CreateDirectory(CQ_DLL)); }
                            catch { Console.WriteLine("酷Q应用目录不存在且无法生成."); return; }
                        }
                        string dlloutfile = Path.Combine(outPutDir, @"app.dll");

                        try { File.Delete(CQ_DLL); } catch { Console.WriteLine("删除DLL失败:" + CQ_DLL); }
                        try { File.Delete(CQ_JSON); } catch { Console.WriteLine("删除JSON失败:" + CQ_JSON); }

                        Console.WriteLine("复制DLL:" + dlloutfile + "->" + CQ_DLL);
                        try
                        { File.Copy(dlloutfile, CQ_DLL); }
                        catch { Console.WriteLine("dll未能复制到酷Q应用目录."); }

                        Console.WriteLine("复制JSON:" + appJsonFile + "->" + CQ_JSON);
                        try { File.Copy(appJsonFile, CQ_JSON); }
                        catch { Console.WriteLine("json未能复制到酷Q应用目录."); }
                    }
                    else { Console.WriteLine("酷Q目录无法识别,将不会复制"); }
                }
                else { Console.WriteLine("未扫描到应用ID,将不会复制"); }
            }
            else { Console.WriteLine("未指定酷Q目录,将不会复制"); }
            Console.WriteLine("CQTool:Done.");
        }

        private static List<FileInfo> 遍历目录(DirectoryInfo srcDir, string v)
        {
            if ((srcDir.Attributes & FileAttributes.Hidden) == FileAttributes.Hidden //隐藏属性
                || (srcDir.Attributes & FileAttributes.System) == FileAttributes.System)//系统文件夹
                return new List<FileInfo>();

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
        static string APP_ID = null;
        private static void 解析文件(string cpp)
        {
            cpp = cpp.Replace("\r\n", "\n").Replace("\r", "\n");
            lines = cpp.Split('\n');
            for (linePos = 0; linePos < lines.Length; linePos++)
            {
                line = lines[linePos];
                //基础信息
                if (line.StartsWith("#define APP_name ")) {
                    app.name = 取引号文本_贪婪(line); }
                else if (line.StartsWith("#define APP_author ")) {
                    app.author = 取引号文本_贪婪(line); }
                else if (line.StartsWith("#define APP_ID ")) {
                    APP_ID = 取引号文本_贪婪(line); }
                else if (line.StartsWith("#define APP_description ")) {
                    app.description = 取引号文本_贪婪(line); }
                else if (line.StartsWith("#define APP_version ")) {
                    app.version = 取引号文本_贪婪(line); }
                else if (line.StartsWith("#define APP_version_id "))
                {
                    var APP_version_id = line.Substring("#define APP_version_id ".Length).Trim();
                    try
                    {
                        app.version_id = int.Parse(APP_version_id);
                        lines[linePos] = "#define APP_version_id " + app.version_id + 1;
                    }
                    catch (Exception) { }
                }
                else if (line.StartsWith("#define CQ_DIR ")) { CQ_DIR = Path.GetDirectoryName( 取引号文本_贪婪(line)); }

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

        static int EveId = 1;
        private static void addEVE(int Type)
        {
            var function = 取文本中间(line, "(", ")");
            var name = function;
            var priority = 30000;
            var reg = new CQregex();
            var msg = false;

            switch (Type)
            {
                case 2:
                case 4:
                case 21:
                    msg = true; break;
            }
            var max = 20;
            for (var end = linePos + max; linePos < end; linePos++)
            //while ( --max > 0)
            {
                line = lines[linePos];
                var s1 = line.IndexOf("//");
                var s2 = line.IndexOf("{");

                //if (s1 == 0) ;//开头就是注释,直接跳过
                if (s1 > 0) { if (0 <= s2 && s2 < s1) break; }//如果存在//,则判断{是否在//前面
                else if (s2 >= 0) break;//如果不存在//,直接判断是否存在{

                if (line.StartsWith("//name:"))
                {
                    name = line.Substring("//name:".Length);
                    //Console.WriteLine(function + ":" + name);
                }
                else if (line.StartsWith("//priority:"))
                {
                    try { priority = int.Parse(line.Substring("//priority:".Length)); } catch (Exception) { }
                }
                else if (msg)
                {
                    if (line.StartsWith("//regex-key:"))
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
            }
            if (reg.expression.Count == 0)
            {
                app._event.Add(new CQevent(id: EveId++, type: Type, name: name, function: function, priority: priority));
            }
            else
            {
                app._event.Add(new CQevent(id: EveId++, type: Type, name: name, function: function, priority: priority, regex: reg));
            }
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

        static int StatusId = 1;
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
            app.status.Add(new CQstatus(name: name, function: function, period: period, title: title, id: StatusId++));
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
            var newstr = text.Substring(start + 1, end - start - 1);
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

            public CQevent(int id, int type, string name, string function, int priority, CQregex regex)
            {
                this.id = id;
                this.type = type;
                this.name = name;
                this.function = function;
                this.priority = priority;
                this.regex = regex;
            }

            public CQevent(int id, int type, string name, string function, int priority)
            {
                this.id = id;
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

            public CQstatus(int id, string name, string title, string function, int period)
            {
                this.id = id;
                this.name = name;
                this.title = title;
                this.function = function;
                this.period = period;
            }

        }

        //测试用的类
        class TestJson
        {
            static void Main(string[] args)
            {
                CQJson j = new CQJson(1, "nnnn", "1.0.0", "tatamis", "yijuhua");
                j.auth.Add(1);
                j.auth.Add(2);
                j.auth.Add(3);
                j.auth.Add(4);
                j.auth.Add(5);

                j._event.Add(new CQevent(1, 1001, "mmm", "fun1", 30000));
                j._event.Add(new CQevent(2, 1002, "mmm", "fun2", 30000));

                CQregex r = new CQregex();
                r.key.Add("QQ");
                r.key.Add("action");
                r.expression.Add("^(?<action>\\S{1,4}?)\\s*(?<qq>\\d{5,10})\\s*?$");

                j._event[1].regex = r;

                j.menu.Add(new CQmenu("menu1", "fun5"));
                j.menu.Add(new CQmenu("menu2", "fun6"));

                string output = JsonConvert.SerializeObject(j);


                Console.WriteLine("预览:");
                Console.WriteLine(output);
                Console.ReadLine();

            }
        }
        class TestMain
        {
            static void Main(string[] args)
            {
                string[] args1 = new string[]
                {
                    @"Z:\CQSDK\CQ_TEST\",
                    @"C:\1\testout\"
                };

                Program.Main(args1);

                string output = JsonConvert.SerializeObject(Program.app);


                Console.WriteLine(output);
                Console.ReadLine();

            }
        }
    }
}