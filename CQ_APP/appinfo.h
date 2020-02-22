#ifdef _DEBUG
#pragma comment(lib,"CQ_SDK_DEBUG.lib")
#else
#pragma comment(lib,"CQ_SDK.lib")
#endif // _DEBUG
#include <CQSDK.h>
//--------开始之前--------

//请右键<CQ_APP>项目,选择<属性>,并修改以下内容:
//	Windows SDK 10.0
//	平台工具集 v142
//您需要设置为您安装的版本
//<CQ_SDK>项目同理
//如果选择v142,则需要用户安装 VC++ runtime 2015 x86

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
//请查阅 https://docs.cqp.im/dev/v9/appid/




//以下内容需要CQJSON小工具支持
//如果您不使用,则需要手动编写JSON
//如果您不使用,请直接转到 appmain.cpp 以继续

//如果使用CQJSON小工具
//需要在<项目属性>的<生成后事件>的<命令行>写入以下命令
//默认已经写入
/*
$(SolutionDir)CQ_Json.exe $(ProjectDir) $(TargetDir)
*/

// 应用名称
#define APP_name "酷Q样例应用"

// 应用版本
#include "appVer.h"

// 应用作者
#define APP_author "Example"

//一句话描述插件用途
#define APP_description "酷Q样例应用(V9应用机制)" //注释不影响解析效果
#define 填写示例 "示例""""\n第二行,"
//              ↑    ↑           ↑
//              ↑始终第一个引号开始,无论是否是真实引号
//                    ↑中间引号全部忽略,与VS解释有所不同
//                                 ↑直接匹配最后一个引号作为结束

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
#define APP_auth_132 "取群信息"
#define APP_auth_131 "取陌生人信息"
#define APP_auth_140 "置讨论组退出"
#define APP_auth_150 "置好友添加请求"
#define APP_auth_151 "置群添加请求"
#define APP_auth_160 "取群成员列表"
#define APP_auth_161 "取群列表"
#define APP_auth_162 "取好友列表"
#define APP_auth_180 "撤回消息"

//酷Q目录,直接生成到酷Q目录
#define CQ_DIR "C:\\CQDIR\\"




//接下来请转到 appmain.cpp 以继续
           