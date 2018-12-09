#pragma comment(lib,"CQ_SDK.lib")
#include <CQSDK.h>

//----我为什么要修改这个ID----
//这是您的插件名称,一个独一无二的名称

//----我应该如何修改这个ID----
//首先您应该修改下方的CQAPPID
//然后修改项目名称      (它会指引VS使用这个名称生成文件)
//最后修改json文件名称

//----我应该修改成什么----
//请查阅 http://d.cqp.me/Pro/开发/基础信息
#define CQAPPID "com.example.demo"

#define CQAPPINFO CQAPIVERTEXT "," CQAPPID

//最重要的一句话
MUST_AppInfo_RETURN(CQAPPID)
















//--------应用正式开始--------

//请加上static,表示这个logger只有本cpp有效
static Logger logger("酷Q样例应用");

EVE_Startup_EX(Startup)
{
	logger.Info("Startup");
}
EVE_Enable_EX(Enable)
{
	logger.Info("Enable");
}

EVE_Disable_EX(Disable)
{
	logger.Info("Disable");
}

EVE_Exit_EX(Exit)
{
	logger.Info("Exit");
}

