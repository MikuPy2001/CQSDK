#pragma once

#include "BaseAPI.h"
#include "StrangerInfo.h"
#include "GroupMemberInfo.h"
#include "FriendInfo.h"
#include "GroupInfo.h"


#include <string>
#include <map>
#include <vector>


inline
namespace CQ {
	//增加运行日志
	整数型 addLog(整数型 优先级, 文本型 类型, 文本型 内容);

	//置致命错误提示,暂时不知道干什么用的
	整数型 setFatal(文本型 错误信息);

	//发送好友消息
	//Auth=106 失败返回负值,成功返回消息ID
	整数型 sendPrivateMsg(长整数型 Account, 文本型 msg);
	//发送好友消息
	//Auth=106 失败返回负值,成功返回消息ID
	整数型 sendPrivateMsg(长整数型 Account, std::string&msg);

	//发送群消息
	//Auth=101 失败返回负值,成功返回消息ID
	整数型 sendGroupMsg(长整数型 群号, 文本型 msg);
	//发送群消息
	//Auth=101 失败返回负值,成功返回消息ID
	整数型 sendGroupMsg(长整数型 群号, std::string&msg);

	//发送讨论组消息
	//Auth=103 失败返回负值,成功返回消息ID
	整数型 sendDiscussMsg(长整数型 讨论组号, 文本型 msg);
	//发送讨论组消息
	//Auth=103 失败返回负值,成功返回消息ID
	整数型 sendDiscussMsg(长整数型 讨论组号, std::string&msg);

	//发送赞 Auth=110
	整数型 sendLike(长整数型 AccountID, 整数型 times);

	//取Cookies,Auth=20 慎用,此接口需要严格授权
	std::string getCookies(std::string domain);

	//接收语音
	//不推荐使用
	//使用完毕后请用CQFree()销毁返回值
	文本型 getRecord(
		文本型 file, // 收到消息中的语音文件名 (file)
		文本型 outformat // 应用所需的格式 mp3,amr,wma,m4a,spx,ogg,wav,flac
	);

	//取CsrfToken (慎用，此接口需要严格授权)
	//Auth=20 即账号网页用到的bkn/g_tk等 慎用,此接口需要严格授权
	整数型 getCsrfToken();

	//取应用目录,返回的路径末尾带"\"
	std::string getAppDirectory();
	
	//取登录账号
	长整数型 getLoginQQ();

	//取登录昵称
	std::string getLoginNick();

	//置群员移除 Auth=120
	整数型 setGroupKick(
		长整数型 群号, 长整数型 AccountID,
		逻辑型 拒绝再加群 = false // 如果为真，则“不再接收此人加群申请”，请慎用
	);

	//置群员禁言 Auth=121
	整数型 setGroupBan(
		长整数型 群号, 长整数型 AccountID,
		长整数型 禁言时间 = 60 // 禁言的时间，单位为秒。如果要解禁，这里填写0
	);

	//置群管理员 Auth=122
	整数型 setGroupAdmin(
		长整数型 群号, 长整数型 AccountID,
		逻辑型 成为管理员 = true // 真/设置管理员 假/取消管理员
	);

	//置群成员专属头衔 Auth=128 需群主权限
	整数型 setGroupSpecialTitle(
		长整数型 群号, 长整数型 AccountID,
		文本型 头衔, // 如果要删除，这里填空
		长整数型 = -1 // 专属头衔有效期，单位为秒。如果永久有效，这里填写-1
	);
	//置群成员专属头衔 Auth=128 需群主权限
	整数型 setGroupSpecialTitle(
		长整数型 群号, 长整数型 AccountID,
		std::string&头衔, // 如果要删除，这里填空
		长整数型 过期时间 = -1 // 专属头衔有效期，单位为秒。如果永久有效，这里填写-1
	);

	//置全群禁言 Auth=123
	整数型 setGroupWholeBan(
		长整数型 群号,
		逻辑型 开启禁言 = true // 真/开启 假/关闭
	);

	//置匿名群员禁言 Auth=124
	整数型 setGroupAnonymousBan(
		长整数型 群号,
		文本型 匿名, // 群消息事件收到的“匿名”参数
		长整数型 禁言时间 = 60 // 禁言的时间，单位为秒。不支持解禁
	);

	//置群匿名设置 Auth=125
	整数型 setGroupAnonymous(长整数型 群号, 逻辑型 开启匿名 = true);

	//置群成员名片 Auth=126
	整数型 setGroupCard(长整数型 群号, 长整数型 AccountID, 文本型 新名片_昵称);

	//置群成员名片 Auth=126
	整数型 setGroupCard(长整数型 群号, 长整数型 AccountID, std::string 新名片_昵称);

	//置群退出 Auth=127 慎用,此接口需要严格授权
	整数型 setGroupLeave(
		长整数型 群号,
		逻辑型 是否解散 = false // 真/解散本群 (群主) 假/退出本群 (管理、群成员)
	);

	//置讨论组退出 Auth=140
	整数型 setDiscussLeave(
		长整数型 讨论组号
	);

	//置好友添加请求 Auth=150
	整数型 setFriendAddRequest(
		文本型 请求反馈标识, // 请求事件收到的“反馈标识”参数
		整数型 反馈类型, // #请求_通过 或 #请求_拒绝
		文本型 备注 // 添加后的好友备注
	);

	//置群添加请求 Auth=151
	整数型 setGroupAddRequest(
		文本型 请求反馈标识, // 请求事件收到的“反馈标识”参数
		整数型 请求类型, // 根据请求事件的子类型区分 #请求_群添加 或 #请求_群邀请
		整数型 反馈类型, // #请求_通过 或 #请求_拒绝
		文本型 理由 // 操作理由，仅 #请求_群添加 且 #请求_拒绝 时可用
	);

	//取群成员信息 (支持缓存) Auth=130
	GroupMemberInfo getGroupMemberInfo(长整数型 群号, 长整数型 AccountID, 逻辑型 不使用缓存 = false);

	//取陌生人信息 (支持缓存) Auth=131
	StrangerInfo getStrangerInfo(长整数型 AccountID, 逻辑型 不使用缓存 = false);

	//取群成员列表 Auth=160
	std::vector<GroupMemberInfo> getGroupMemberList(长整数型 群号);

	//取群列表 Auth=161
	std::map<long long, std::string> getGroupList();

	//撤回消息 Auth=180
	整数型 deleteMsg(长整数型 MsgId);

	//9.20添加


	//是否支持发送图片，返回大于 0 为支持，等于 0 为不支持
	bool canSendImage();

	//是否支持发送语音，返回大于 0 为支持，等于 0 为不支持
	bool canSendRecord();

	//接收图片，并返回图片文件绝对路径
	std::string getImage(std::string file);

	//接收语音
	std::string getRecord(
		std::string& file, // 收到消息中的语音文件名 (file)
		std::string outformat // 应用所需的格式 mp3,amr,wma,m4a,spx,ogg,wav,flac
	);

	//9.25添加

	//取好友列表 Auth=162
	std::vector <FriendInfo> getFriendList();

	//取群信息(支持缓存) Auth=132
	GroupInfo getGroupInfo(长整数型 群号, 逻辑型 不使用缓存 = false);

	//取登录账号
	长整数型 getLoginAccount();


	// 其他不重要的

	//如果API调用返回错误代码
	//则可以使用本函数获取相关中文信息
	const char * getlasterrmsg();
}