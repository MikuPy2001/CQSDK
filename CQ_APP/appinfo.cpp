#include onec
#pragma comment(lib,"CQ_SDK.lib")
//--------开始之前--------

//请右键<CQ_APP>项目,选择<属性>,并修改以下内容:
//	Windows SDK
//	平台工具集
//您需要设置为您安装的版本
//<CQ_SDK>项目同理

//然后修改上方x64为x86,酷Q插件不支持64位

//最后请尝试编译此项目,并排除可能的报错

//最后的最后
//请不要发布debug版
//至少让你的应用在其他电脑上正常运行再发布(它在我的电脑上好好的呀?)



//--------应用信息--------

#define APP_ID "com.example.demo"
//----这是什么----
//这是您的插件名称,一个独一无二的名称
//----我应该按照什么原则命名----
//请查阅 http://d.cqp.me/Pro/开发/基础信息


#define CQAPPINFO CQAPIVERTEXT "," APP_ID
MUST_AppInfo_RETURN(APP_ID)


//以下内容需要CQJSON小工具支持
//需要在<生成后事件>的<命令行>写入以下命令
/*

*/

// 应用名称
#define APP_anem "酷Q样例应用"

// 应用版本
#define APP_version "1.0.0(alpha)"

// 应用顺序版本（每次发布时小工具自动将其+1）
#define APP_version_id 0

// 应用作者
#define APP_author "Example"

//一句话描述插件用途
#define APP_description "酷Q样例应用(V9应用机制)"

//权限确认,请只保留关键权限.
//#define APP_auth_20 "取Cookies"//[敏感]
//#define APP_auth_30 "接收语音"
#define APP_auth_101 "发送群消息"
#define APP_auth_103 "发送讨论组消息"
#define APP_auth_106 "发送私聊消息"
//#define APP_auth_110 "发送赞"//[敏感]
#define APP_auth_120 "置群员移除"
#define APP_auth_121 "置群员禁言"
#define APP_auth_122 "置群管理员"
#define APP_auth_123 "置全群禁言"
#define APP_auth_124 "置匿名群员禁言"
#define APP_auth_125 "置群匿名设置"
#define APP_auth_126 "置群成员名片"
//#define APP_auth_127 "置群退出"//[敏感]
#define APP_auth_128 "置群成员专属头衔"
#define APP_auth_130 "取群成员信息"
#define APP_auth_131 "取陌生人信息"
#define APP_auth_140 "置讨论组退出"
#define APP_auth_150 "置好友添加请求"
#define APP_auth_151 "置群添加请求"
#define APP_auth_160 "取群成员列表"
#define APP_auth_161 "取群列表"
#define APP_auth_180 "撤回消息"

//酷Q目录,直接生成到酷Q目录
#define CQ_DIR "D:\\CQP\\"


//接下来请转到 appmain.cpp 以继续