using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CQJson
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = System.Diagnostics.Process.GetCurrentProcess().MainModule.FileName;
            string help = "从源文件中提取插件信息,用于生成.\n\n" +
               str + " <源文件目录> <生成目录> (酷Q目录)\n\n" +
               "此命令将扫描 源文件目录 中所有CPP文件,\n" +
               "并提取包含信息内容的宏,用于生成JSON,\n" +
               "请查看CQ_APP项目相关源文件了解更详细内容";
            if(args.Length==0)
            {
                Console.Write(help); return;
            }
            else if (args[0] == "/?")
            {
                Console.Write(help); return;
            }

            DirectoryInfo srcDir = new DirectoryInfo(args[0]);
            if (!srcDir.Exists)
            {
                Console.Write("源文件目录不存在");return;
            }
            DirectoryInfo diDir = new DirectoryInfo(args[2]);
            if (!diDir.Exists)
            {
                Console.Write("生成目录不存在"); return;
            }



        }
    }
}
