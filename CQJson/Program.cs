using Newtonsoft.Json;
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;

namespace CQJson
{
    class Program
    {
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

    }

    public class CQJson
    {
        public int ret = 1;
        public int apiver = 9;
        public int version_id;
        public string name;
        public string version;
        public string author;
        public string description;
        [JsonProperty(PropertyName = "event")]
        public List<CQevent> _event;
        public List<CQmenu> menu;
        public List<CQstatus> status;
        public List<int> auth;
    }
    public class CQmenu
    {
        public int  id;
        public int type;
        public string name;
        public string function;
        public int priority;

    }
    public class CQevent
    {
        public int id;
        public int type;
        public string name;
        public string function;
        public int priority;

        public CQregex regex;
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
}
