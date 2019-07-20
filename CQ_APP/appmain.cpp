






//您应当先看appinfo






#include <CQSDK.h>
#include "appinfo.h"
//--------应用正式开始--------
//本cpp讲述如何在插件启动和停止时执行必要的初始化和收尾工作



MUST_AppInfo_RETURN(CQAPIVERTEXT "," APP_ID)



//请加上static,表示这个logger只有本cpp有效
static Logger logger("酷Q样例应用");





//使用EVE_开头的宏指令
//可以快速生成一条符合要求的事件函数
//使您无需关心这个函数需要怎样的格式
//即可快速开始使用
EVE_Startup_EX(Startup)
//name:酷Q启动
//priority:30000
//以上2行为注释,用于json自动生成
//name为事件名称,一般标识用途,不需要表明事件类型
//priority为事件优先级(参见 cq.im/deveventpriority)
//开头必须为<//name:>或<//priority:>,不得有空格等
//如果没有name,默认为事件名
//如果没有priority,默认为30000
{
	logger.Info("Startup");
	//本函数在执行周期最多只会执行一次
	//可以在这里加载全局资源
}






EVE_Enable_EX(Enable)
//name:禁用将无法加载数保
//priority:30000
{
	logger.Info("Enable");
	//应用有可能多次启用
	//可以在这里加载运行周期内才需要的资源
}






EVE_Disable_EX(Disable)
//name:禁用将不能保存数据
//priority:30000
{
	logger.Info("Disable");
	//应用有可能多次停止
	//但是停止后dll还可以继续运行
	//但是收不到任何事件也不能套用任何API
}






EVE_Exit_EX(Exit)
//name:退出清理
//priority:30000
{
	logger.Info("Exit");
	//本函数执行以后,酷Q会短时间内结束运行
}






//接下来请转向 Msg.cpp 以继续