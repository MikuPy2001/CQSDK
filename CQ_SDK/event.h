#pragma once

// 拦截此条消息，不再传递给其他应用
//注意：应用优先级设置为最高(10000)时，不得使用本返回值
#define 消息_拦截 1
// 将此消息继续传递给其他应用
#define 消息_忽略 0

#define 悬浮窗_绿 1
#define 悬浮窗_橙 2
#define 悬浮窗_红 3
#define 悬浮窗_深红 4
#define 悬浮窗_黑 5
#define 悬浮窗_灰 6


/*
返回应用的ApiVer、Appid，打包后将不会调用
*/
#define MUST_AppInfo CQEVENT(const char*, AppInfo, 0)()

/*
返回应用的ApiVer、Appid，打包后将不会调用
*/
#define MUST_AppInfo_RETURN(CQAPPID) MUST_AppInfo{return CQAPIVERTEXT "," CQAPPID;}

/*
本宏已失效,请使用 getAuthCode(); 直接获取, 此函数在CQAPI.h中

应用AuthCode接收

请保存 AuthCode ,此值是调用CQAPI的凭证

请不要在本函数添加其他代码
*/
//#define MUST_Initialize CQEVENT(int, Initialize, 4)(int AuthCode)

///////////////////////////////// 事件 相关内容 /////////////////////////////////
//extern "C" __declspec(dllexport) void __stdcall Int32(int a){}//@4
//extern "C" __declspec(dllexport) void __stdcall Char(const char* a){}//@4
//extern "C" __declspec(dllexport) void __stdcall Int64(long long a){}//@8

/*
酷Q启动(Type=1001)

本子程序会在酷Q【主线程】中被调用。
无论本应用是否被启用，本函数都会在酷Q启动后执行一次，请在这里执行插件初始化代码。
请务必尽快返回本子程序，否则会卡住其他插件以及主程序的加载。

名字如果使用下划线开头需要改成双下划线
请固定返回 0
*/
#define EVE_Startup(Name) CQEVENT(int, Name, 0)()
/*
酷Q启动(Type=1001)

本子程序会在酷Q【主线程】中被调用。
无论本应用是否被启用，本函数都会在酷Q启动后执行一次，请在这里执行插件初始化代码。
请务必尽快返回本子程序，否则会卡住其他插件以及主程序的加载。

名字如果使用下划线开头需要改成双下划线
*/
#define EVE_Startup_EX(Name)\
void Name##_EX();\
EVE_Startup(Name){\
	Name##_EX();\
	return 0;\
}\
void Name##_EX()

/*
酷Q退出(Type=1002)

本子程序会在酷Q【主线程】中被调用。
无论本应用是否被启用，本函数都会在酷Q退出前执行一次，请在这里执行插件关闭代码。

名字如果使用下划线开头需要改成双下划线
请固定返回0，返回后酷Q将很快关闭，请不要再通过线程等方式执行其他代码。
*/
#define EVE_Exit(Name) CQEVENT(int, Name, 0)()
/*
酷Q退出(Type=1002)

本子程序会在酷Q【主线程】中被调用。
无论本应用是否被启用，本函数都会在酷Q退出前执行一次，请在这里执行插件关闭代码。

名字如果使用下划线开头需要改成双下划线
请固定返回0，返回后酷Q将很快关闭，请不要再通过线程等方式执行其他代码。
*/
#define EVE_Exit_EX(Name)\
void Name##_EX();\
EVE_Exit(Name){\
	Name##_EX();\
	return 0;\
}\
void Name##_EX()
/*
应用已被启用(Type=1003)

当应用被启用后，将收到此事件。
如果酷Q载入时应用已被启用，则在 EVE_Startup(Type=1001,酷Q启动) 被调用后，本函数也将被调用一次。
如非必要，不建议在这里加载窗口。（可以添加菜单，让用户手动打开窗口）

名字如果使用下划线开头需要改成双下划线
请固定返回0。
*/
#define EVE_Enable(Name) CQEVENT(int, Name, 0)()
/*
应用已被启用(Type=1003)

当应用被启用后，将收到此事件。
如果酷Q载入时应用已被启用，则在 EVE_Startup(Type=1001,酷Q启动) 被调用后，本函数也将被调用一次。
如非必要，不建议在这里加载窗口。（可以添加菜单，让用户手动打开窗口）

名字如果使用下划线开头需要改成双下划线
请固定返回0。
*/
#define EVE_Enable_EX(Name)\
void Name##_EX();\
EVE_Enable(Name){\
	Name##_EX();\
	return 0;\
}\
void Name##_EX()

/*
应用将被停用(Type=1004)

当应用被停用前，将收到此事件。
如果酷Q载入时应用已被停用，则本函数【不会】被调用。
无论本应用是否被启用，酷Q关闭前本函数都【不会】被调用。

名字如果使用下划线开头需要改成双下划线
请固定返回0。
*/
#define EVE_Disable(Name) CQEVENT(int, Name, 0)()

/*
应用将被停用(Type=1004)

当应用被停用前，将收到此事件。
如果酷Q载入时应用已被停用，则本函数【不会】被调用。
无论本应用是否被启用，酷Q关闭前本函数都【不会】被调用。

名字如果使用下划线开头需要改成双下划线
请固定返回0。
*/
#define EVE_Disable_EX(Name)\
void Name##_EX();\
EVE_Disable(Name){\
	Name##_EX();\
	return 0;\
}\
void Name##_EX()
/*
私聊消息(Type=21)
此事件拥有EX版本,建议使用EX版本

subType		子类型，11/来自好友 1/来自在线状态 2/来自群 3/来自讨论组
msgId		消息ID
fromQQ		来源QQ
msg			消息内容
font		字体

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线

返回值*不能*直接返回文本
如果要回复消息，请调用api发送，并且 返回(#消息_拦截) - 截断本条消息，不再继续处理 //注意：应用优先级设置为"最高"(10000)时，不得使用本返回值
如果不回复消息，交由之后的应用/过滤器处理 返回(#消息_忽略) - 忽略本条消息
*/
#define EVE_PrivateMsg(Name) CQEVENT(int, Name, 24)(int subType, int msgId, long long fromQQ, const char* msg, int font)
/*
私聊消息(Type=21)

subType		子类型，11/来自好友 1/来自在线状态 2/来自群 3/来自讨论组
msgId	消息ID
fromQQ		来源QQ
msg			私聊消息
font		字体

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线

返回值*不能*直接返回文本
如果要回复消息，请调用api发送，并且 返回(#消息_拦截) - 截断本条消息，不再继续处理 //注意：应用优先级设置为"最高"(10000)时，不得使用本返回值
如果不回复消息，交由之后的应用/过滤器处理 返回(#消息_忽略) - 忽略本条消息
*/
#define EVE_PrivateMsg_EX(Name)																	\
	void Name(CQ::PrivateMsgEvent & e);															\
	EVE_PrivateMsg(Name)																		\
	{																							\
		CQ::PrivateMsgEvent tep(subType, msgId, fromQQ, msg, font);								\
		Name(tep);																				\
		return tep._EVEret;																		\
	}																							\
	void Name(CQ::PrivateMsgEvent & e)

/*
群消息(Type=2)

subType		子类型，目前固定为1
msgId		消息ID
fromGroup	来源群号
fromQQ		来源QQ号
fromAnonymous 来源匿名者
msg			消息内容
font		字体

如果消息来自匿名者,fromQQ 固定为 80000000,可使用工具将 fromAnonymous 转换为 匿名者信息

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线

返回值*不能*直接返回文本
如果要回复消息，请调用api发送，并且 返回(#消息_拦截) - 截断本条消息，不再继续处理 //注意：应用优先级设置为"最高"(10000)时，不得使用本返回值
如果不回复消息，交由之后的应用/过滤器处理 返回(#消息_忽略) - 忽略本条消息
*/
#define EVE_GroupMsg(Name) CQEVENT(int, Name, 36)(int subType, int msgId, long long fromGroup, long long fromQQ, const char* fromAnonymous, const char* msg, int font)
/*
群消息(Type=2)

subType 子类型，目前固定为1
msgId 消息ID
fromGroup 来源群号
fromQQ 来源QQ号
fromAnonymous 来源匿名者
msg 消息内容
font 字体

如果消息来自匿名者,isAnonymous() 返回 true, 可使用 getFromAnonymousInfo() 获取 匿名者信息

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线

返回值*不能*直接返回文本
如果要回复消息，请调用api发送，并且 返回(#消息_拦截) - 截断本条消息，不再继续处理 //注意：应用优先级设置为"最高"(10000)时，不得使用本返回值
如果不回复消息，交由之后的应用/过滤器处理 返回(#消息_忽略) - 忽略本条消息
*/
#define EVE_GroupMsg_EX(Name) 																	\
	void Name(CQ::GroupMsgEvent & e);															\
	EVE_GroupMsg(Name)																			\
	{																							\
		CQ::GroupMsgEvent tep(subType, msgId, fromGroup, fromQQ, fromAnonymous, msg, font);		\
		Name(tep);																				\
		return tep._EVEret;																		\
	}																							\
	void Name(CQ::GroupMsgEvent & e)

/*
讨论组消息(Type=4)

subtype		子类型，目前固定为1
msgId		消息ID
fromDiscuss	来源讨论组
fromQQ		来源QQ号
msg			消息内容
font		字体

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线

返回值*不能*直接返回文本
如果要回复消息，请调用api发送，并且 返回(#消息_拦截) - 截断本条消息，不再继续处理 //注意：应用优先级设置为"最高"(10000)时，不得使用本返回值
如果不回复消息，交由之后的应用/过滤器处理 返回(#消息_忽略) - 忽略本条消息
*/
#define EVE_DiscussMsg(Name) CQEVENT(int, Name, 32)(int subType, int msgId, long long fromDiscuss, long long fromQQ, const char* msg, int font)
/*
讨论组消息(Type=4)

subtype		子类型，目前固定为1
msgId		消息ID
fromDiscuss	来源讨论组
fromQQ		来源QQ号
msg			消息内容
font		字体

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线

返回值*不能*直接返回文本
如果要回复消息，请调用api发送，并且 返回(#消息_拦截) - 截断本条消息，不再继续处理 //注意：应用优先级设置为"最高"(10000)时，不得使用本返回值
如果不回复消息，交由之后的应用/过滤器处理 返回(#消息_忽略) - 忽略本条消息
*/
#define EVE_DiscussMsg_EX(Name)																	\
	void Name(CQ::DiscussMsgEvent & e);															\
	EVE_DiscussMsg(Name)																		\
	{																							\
		CQ::DiscussMsgEvent tep(subType, msgId, fromDiscuss, fromQQ, msg, font);					\
		Name(tep);																				\
		return tep._EVEret;																		\
	}																							\
	void Name(CQ::DiscussMsgEvent & e)

/*
群文件上传事件(Type=11)

subType 子类型，目前固定为1
sendTime 发送时间(时间戳)
fromGroup 来源群号
fromQQ 来源QQ号
file 上传文件信息,使用 <其他_转换_文本到群文件> 将本参数转换为有效数据,待编辑

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线

返回值*不能*直接返回文本
如果要回复消息，请调用api发送，并且 返回(#消息_拦截) - 截断本条消息，不再继续处理 //注意：应用优先级设置为"最高"(10000)时，不得使用本返回值
如果不回复消息，交由之后的应用/过滤器处理 返回(#消息_忽略) - 忽略本条消息
*/
#define EVE_GroupUpload(Name) CQEVENT(int, Name, 28)(int subType, int sendTime, long long fromGroup,long long fromQQ, const char* file)

/*
群事件-管理员变动(Type=101)

subtype			子类型，1/被取消管理员 2/被设置管理员
sendTime 发送时间(时间戳)
fromGroup		来源群号
beingOperateQQ	被操作QQ

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线

返回值*不能*直接返回文本
如果要回复消息，请调用api发送，并且 返回(#消息_拦截) - 截断本条消息，不再继续处理 //注意：应用优先级设置为"最高"(10000)时，不得使用本返回值
如果不回复消息，交由之后的应用/过滤器处理 返回(#消息_忽略) - 忽略本条消息
*/
#define EVE_System_GroupAdmin(Name) CQEVENT(int, Name, 24)(int subType, int sendTime, long long fromGroup, long long beingOperateQQ)/*
/*
群事件-管理员变动(Type=101)

subtype			子类型，1/被取消管理员 2/被设置管理员
sendTime 发送时间(时间戳)
fromGroup		来源群号
beingOperateQQ	被操作QQ

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线

返回值*不能*直接返回文本
如果要回复消息，请调用api发送，并且 返回(#消息_拦截) - 截断本条消息，不再继续处理 //注意：应用优先级设置为"最高"(10000)时，不得使用本返回值
如果不回复消息，交由之后的应用/过滤器处理 返回(#消息_忽略) - 忽略本条消息
*/
#define EVE_System_GroupAdmin_EX(Name) \
	void Name(CQ::SystemGroupAdminEvent & e);\
	EVE_System_GroupAdmin(Name)\
	{\
		CQ::SystemGroupAdminEvent tep( subType, sendTime, fromGroup, beingOperateQQ);\
		Name(tep);\
		return tep._EVEret;																		\
	}\
	void Name(CQ::SystemGroupAdminEvent & e)

/*
群事件-群成员减少(Type=102)

subtype		子类型，1/群员离开 2/群员被踢 3/自己(即登录号)被踢
sendTime 发送时间(时间戳)
fromGroup	来源群号
fromQQ		操作者QQ(仅子类型为2、3时存在)
beingOperateQQ 被操作QQ

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线

返回值*不能*直接返回文本
如果要回复消息，请调用api发送，并且 返回(#消息_拦截) - 截断本条消息，不再继续处理 //注意：应用优先级设置为"最高"(10000)时，不得使用本返回值
如果不回复消息，交由之后的应用/过滤器处理 返回(#消息_忽略) - 忽略本条消息
*/
#define EVE_System_GroupMemberDecrease(Name) CQEVENT(int, Name, 32)(int subType, int sendTime, long long fromGroup, long long fromQQ, long long beingOperateQQ)

/*
群事件-群成员增加(Type=103)

subtype 子类型，1/管理员已同意 2/管理员邀请
sendTime 发送时间(时间戳)
fromGroup 来源群号
fromQQ 操作者QQ(即管理员QQ)
beingOperateQQ 被操作QQ(即加群的QQ)

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线

返回值*不能*直接返回文本
如果要回复消息，请调用api发送，并且 返回(#消息_拦截) - 截断本条消息，不再继续处理 //注意：应用优先级设置为"最高"(10000)时，不得使用本返回值
如果不回复消息，交由之后的应用/过滤器处理 返回(#消息_忽略) - 忽略本条消息
*/
#define EVE_System_GroupMemberIncrease(Name) CQEVENT(int, Name, 32)(int subType, int sendTime, long long fromGroup, long long fromQQ, long long beingOperateQQ)

/*
好友事件-好友已添加(Type=201)

subtype 子类型，目前固定为1
sendTime 发送时间(时间戳)
fromQQ 来源QQ

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线

返回值*不能*直接返回文本
如果要回复消息，请调用api发送，并且 返回(#消息_拦截) - 截断本条消息，不再继续处理 //注意：应用优先级设置为"最高"(10000)时，不得使用本返回值
如果不回复消息，交由之后的应用/过滤器处理 返回(#消息_忽略) - 忽略本条消息
*/
#define EVE_Friend_Add(Name) CQEVENT(int, Name, 16)(int subType, int sendTime, long long fromQQ)
/*
好友事件-好友已添加(Type=201)

subtype 子类型，目前固定为1
msgId 消息ID
fromQQ 来源QQ

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线

返回值*不能*直接返回文本
如果要回复消息，请调用api发送，并且 返回(#消息_拦截) - 截断本条消息，不再继续处理 //注意：应用优先级设置为"最高"(10000)时，不得使用本返回值
如果不回复消息，交由之后的应用/过滤器处理 返回(#消息_忽略) - 忽略本条消息
*/
#define EVE_Friend_Add_EX(Name) \
	void Name(CQ::FriendAddEvent & e);\
	EVE_Friend_Add(Name)\
	{\
		CQ::FriendAddEvent tep(subType, sendTime, fromQQ);\
		Name(tep);\
		return tep._EVEret;																		\
	}\
	void Name(CQ::FriendAddEvent & e)

/*
请求-好友添加(Type=301)

subtype 子类型，目前固定为1
sendTime 发送时间(时间戳)
fromQQ 来源QQ
msg 附言
responseFlag 反馈标识(处理请求用)

置好友添加请求 (responseFlag, #请求_通过)

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线

返回值*不能*直接返回文本
如果要回复消息，请调用api发送，并且 返回(#消息_拦截) - 截断本条消息，不再继续处理 //注意：应用优先级设置为"最高"(10000)时，不得使用本返回值
如果不回复消息，交由之后的应用/过滤器处理 返回(#消息_忽略) - 忽略本条消息
*/
#define EVE_Request_AddFriend(Name) CQEVENT(int, Name, 24)(int subType, int sendTime, long long fromQQ, const char* msg, const char* responseFlag)
/*
请求-好友添加(Type=301)

subtype 子类型，目前固定为1
sendTime 发送时间(时间戳)
fromQQ 来源QQ
msg 附言
responseFlag 反馈标识(处理请求用)

置好友添加请求 (responseFlag, #请求_通过)

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线

返回值*不能*直接返回文本
如果要回复消息，请调用api发送，并且 返回(#消息_拦截) - 截断本条消息，不再继续处理 //注意：应用优先级设置为"最高"(10000)时，不得使用本返回值
如果不回复消息，交由之后的应用/过滤器处理 返回(#消息_忽略) - 忽略本条消息
*/
#define EVE_Request_AddFriend_EX(Name)															\
	void Name(CQ::RequestAddFriendEvent & e);													\
	EVE_Request_AddFriend(Name)																	\
	{																							\
		CQ::RequestAddFriendEvent tep(subType, sendTime, fromQQ, msg, responseFlag);	\
		Name(tep);																				\
		return tep._EVEret;																		\
	}																							\
	void Name(CQ::RequestAddFriendEvent & e)

/*
请求-群添加(Type=302)

subtype 子类型，1/他人申请入群 2/自己(即登录号)受邀入群
sendTime 发送时间(时间戳)
fromGroup 来源群号
fromQQ 来源QQ
msg 附言
responseFlag 反馈标识(处理请求用)

如果 subtype ＝ 1
置群添加请求 (responseFlag, #请求_群添加, #请求_通过)
如果 subtype ＝ 2
置群添加请求 (responseFlag, #请求_群邀请, #请求_通过)

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线

返回值*不能*直接返回文本
如果要回复消息，请调用api发送，并且 返回(#消息_拦截) - 截断本条消息，不再继续处理 //注意：应用优先级设置为"最高"(10000)时，不得使用本返回值
如果不回复消息，交由之后的应用/过滤器处理 返回(#消息_忽略) - 忽略本条消息
*/
#define EVE_Request_AddGroup(Name) CQEVENT(int, Name, 32)(int subType, int sendTime, long long fromGroup, long long fromQQ, const char* msg, const char* responseFlag)
/*
请求-群添加(Type=302)

subtype 子类型，1/他人申请入群 2/自己(即登录号)受邀入群
sendTime 发送时间(时间戳)
fromGroup 来源群号
fromQQ 来源QQ
msg 附言
responseFlag 反馈标识(处理请求用)

如果 subtype ＝ 1
置群添加请求 (responseFlag, #请求_群添加, #请求_通过)
如果 subtype ＝ 2
置群添加请求 (responseFlag, #请求_群邀请, #请求_通过)

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)
名字如果使用下划线开头需要改成双下划线

返回值*不能*直接返回文本
如果要回复消息，请调用api发送，并且 返回(#消息_拦截) - 截断本条消息，不再继续处理 //注意：应用优先级设置为"最高"(10000)时，不得使用本返回值
如果不回复消息，交由之后的应用/过滤器处理 返回(#消息_忽略) - 忽略本条消息
*/
#define EVE_Request_AddGroup_EX(Name) \
	void Name(CQ::RequestAddGroupEvent & e);\
	EVE_Request_AddGroup(Name)\
	{\
		CQ::RequestAddGroupEvent tep(subType, sendTime, fromGroup, fromQQ, msg, responseFlag);\
		Name(tep); 										\
		return tep._EVEret;\
	}\
	void Name(CQ::RequestAddGroupEvent & e)

/*
菜单

可在 .json 文件中设置菜单数目、函数名
如果不使用菜单，请在 .json 及此处删除无用菜单
名字如果使用下划线开头需要改成双下划线

返回值*不能*直接返回文本
如果要回复消息，请调用api发送，并且 返回(#消息_拦截) - 截断本条消息，不再继续处理 //注意：应用优先级设置为"最高"(10000)时，不得使用本返回值
如果不回复消息，交由之后的应用/过滤器处理 返回(#消息_忽略) - 忽略本条消息
*/
#define EVE_Menu(Name) CQEVENT(int, Name, 0)()
/*
菜单

可在 .json 文件中设置菜单数目、函数名
如果不使用菜单，请在 .json 及此处删除无用菜单
名字如果使用下划线开头需要改成双下划线

返回值*不能*直接返回文本
如果要回复消息，请调用api发送，并且 返回(#消息_拦截) - 截断本条消息，不再继续处理 //注意：应用优先级设置为"最高"(10000)时，不得使用本返回值
如果不回复消息，交由之后的应用/过滤器处理 返回(#消息_忽略) - 忽略本条消息
*/
#define EVE_Menu_EX(Name)\
void Name##_EX();\
EVE_Menu(Name){\
	Name##_EX();\
}\
Name##_EX()
/*
悬浮窗

请使用EX版本
emmm,因为一些原因,悬浮窗暂时不可用...

本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize)。
名字如果使用下划线开头需要改成双下划线
*/
#define EVE_Status(Name) CQEVENT(const char*, Name, 0)()
/**
 * 悬浮窗.
 * <p>
 * 请设置 e.data e.dataf e.color 其他函数保持不动即可
 * <p>
 * <p>
 * 本子程序会在酷Q【线程】中被调用，请注意使用对象等需要初始化(CoInitialize,CoUninitialize).
 * <p>
 * 名字如果使用下划线开头需要改成双下划线
 *
 * @param e
 */
#define EVE_Status_EX(Name)					\
	void Name(CQ::StatusEvent & e);\
	EVE_Status(Name)\
	{\
		CQ::StatusEvent tep;\
		static std::string ret;\
		Name(tep);										\
		ret = CQ::statusEVEreturn(tep);\
		return ret.c_str();\
	}\
	void Name(CQ::StatusEvent & e)
