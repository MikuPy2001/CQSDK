/*
CoolQ SDK for VS2017
Api Version 9.13
Written by MukiPy2001 & Thanks for the help of orzFly and Coxxs
*/
#pragma once

#include "Base.h"

// 调试       灰色
#define Log_Debug 0
// 信息       黑色
#define Log_Info 10
// 信息(成功) 紫色
#define Log_InfoSuccess 11
// 信息(接收) 蓝色
#define Log_InfoRecv 12
// 信息(发送) 绿色
#define Log_InfoSend 13
// 警告       橙色
#define Log_Warning 20
// 错误       红色
#define Log_Error 30
// 致命错误   深红
#define Log_Fatal 40

#define 请求_通过 1
#define 请求_拒绝 2

#define 请求_群添加 1
#define 请求_群邀请 2
inline
namespace CQ {
	//增加运行日志
	CQAPI(CQ_addLog, 整数型)(
		整数型 AuthCode,
		整数型 优先级,// #Log_ 开头常量
		文本型 类型,//
		文本型 内容//
		);
	//发送好友消息
	//Auth=106 失败返回负值,成功返回消息ID
	CQAPI(CQ_sendPrivateMsg, 整数型)(
		整数型 AuthCode,
		长整数型 AccountID,// 目标账号
		文本型 msg// 消息内容
		);
	//发送群消息
	//Auth=101 失败返回负值,成功返回消息ID
	CQAPI(CQ_sendGroupMsg, 整数型)(
		整数型 AuthCode,
		长整数型 群号,// 目标群
		文本型 msg// 消息内容
		);
	//发送讨论组消息
	//Auth=103 失败返回负值,成功返回消息ID
	CQAPI(CQ_sendDiscussMsg, 整数型)(
		整数型 AuthCode,
		长整数型 讨论组号,// 目标讨论组
		文本型 msg// 消息内容
		);
	//发送赞V2 Auth=110
	CQAPI(CQ_sendLikeV2, 整数型)(
		整数型 AuthCode,
		长整数型 AccountID,// 目标账号
		整数型 times// 赞的次数，最多10次
		);
	//取CsrfToken (慎用，此接口需要严格授权)
	//Auth=20 即账号网页用到的bkn/g_tk等 慎用,此接口需要严格授权
	CQAPI(CQ_getCsrfToken, 整数型)(
		整数型 AuthCode
		);
	//取应用目录
	//返回的路径末尾带"\"
	CQAPI(CQ_getAppDirectory, 文本型)(
		整数型 AuthCode
		);
	//取登录账号
	CQAPI(CQ_getLoginQQ, 长整数型)(
		整数型 AuthCode
		);
	//取登录昵称
	CQAPI(CQ_getLoginNick, 文本型)(
		整数型 AuthCode
		);
	//置群员移除 Auth=120
	CQAPI(CQ_setGroupKick, 整数型)(
		整数型 AuthCode,
		长整数型 群号,// 目标群
		长整数型 AccountID,// 目标账号
		逻辑型 拒绝再加群// 如果为真，则“不再接收此人加群申请”，请慎用
		);
	//置群员禁言 Auth=121
	CQAPI(CQ_setGroupBan, 整数型)(
		整数型 AuthCode,
		长整数型 群号,// 目标群
		长整数型 AccountID,// 目标账号
		长整数型 禁言时间// 禁言的时间，单位为秒。如果要解禁，这里填写0
		);
	//置群管理员 Auth=122
	CQAPI(CQ_setGroupAdmin, 整数型)(
		整数型 AuthCode,
		长整数型 群号,// 目标群
		长整数型 AccountID,// 被设置的账号
		逻辑型 成为管理员// 真/设置管理员 假/取消管理员
		);
	//置群成员专属头衔 Auth=128 需群主权限
	CQAPI(CQ_setGroupSpecialTitle, 整数型)(
		整数型 AuthCode,
		长整数型 群号,// 目标群
		长整数型 AccountID,// 目标账号
		文本型 头衔,// 如果要删除，这里填空
		长整数型 过期时间// 专属头衔有效期，单位为秒。如果永久有效，这里填写-1
		);
	//置全群禁言 Auth=123
	CQAPI(CQ_setGroupWholeBan, 整数型)(
		整数型 AuthCode,
		长整数型 群号,// 目标群
		逻辑型 开启禁言// 真/开启 假/关闭
		);
	//置匿名群员禁言 Auth=124
	CQAPI(CQ_setGroupAnonymousBan, 整数型)(
		整数型 AuthCode,
		长整数型 群号,// 目标群
		文本型 匿名,// 群消息事件收到的“匿名”参数
		长整数型 禁言时间// 禁言的时间，单位为秒。不支持解禁
		);
	//置群匿名设置 Auth=125
	CQAPI(CQ_setGroupAnonymous, 整数型)(
		整数型 AuthCode,
		长整数型 群号,//
		逻辑型 开启匿名//
		);
	//置群成员名片 Auth=126
	CQAPI(CQ_setGroupCard, 整数型)(
		整数型 AuthCode,
		长整数型 群号,// 目标群
		长整数型 AccountID,// 被设置的账号
		文本型 新名片_昵称//
		);
	//置群退出 Auth=127 慎用,此接口需要严格授权
	CQAPI(CQ_setGroupLeave, 整数型)(
		整数型 AuthCode,
		长整数型 群号,// 目标群
		逻辑型 是否解散// 真/解散本群 (群主) 假/退出本群 (管理、群成员)
		);
	//置讨论组退出 Auth=140
	CQAPI(CQ_setDiscussLeave, 整数型)(
		整数型 AuthCode,
		长整数型 讨论组号// 目标讨论组
		);
	//置好友添加请求 Auth=150
	CQAPI(CQ_setFriendAddRequest, 整数型)(
		整数型 AuthCode,
		文本型 请求反馈标识,// 请求事件收到的“反馈标识”参数
		整数型 反馈类型,// #请求_通过 或 #请求_拒绝
		文本型 备注// 添加后的好友备注
		);
	//置群添加请求 Auth=151
	CQAPI(CQ_setGroupAddRequestV2, 整数型)(
		整数型 AuthCode,
		文本型 请求反馈标识,// 请求事件收到的“反馈标识”参数
		整数型 请求类型,// 根据请求事件的子类型区分 #请求_群添加 或 #请求_群邀请
		整数型 反馈类型,// #请求_通过 或 #请求_拒绝
		文本型 理由// 操作理由，仅 #请求_群添加 且 #请求_拒绝 时可用
		);
	//置致命错误提示
	CQAPI(CQ_setFatal, 整数型)(
		整数型 AuthCode,
		文本型 错误信息//
		);
	//取群成员信息 (支持缓存) Auth=130
	CQAPI(CQ_getGroupMemberInfoV2, 文本型)(
		整数型 AuthCode,
		长整数型 群号,// 目标账号所在群
		长整数型 AccountID,// 目标账号
		逻辑型 不使用缓存
		);
	//取陌生人信息 (支持缓存) Auth=131
	CQAPI(CQ_getStrangerInfo, 文本型)(
		整数型 AuthCode,
		长整数型 AccountID,// 目标账号
		逻辑型 不使用缓存
		);
	//取群成员列表 Auth=160
	CQAPI(CQ_getGroupMemberList, 文本型)(
		整数型 AuthCode,
		长整数型 群号// 目标账号所在群
		);
	//取群列表 Auth=161
	CQAPI(CQ_getGroupList, 文本型)(
		整数型 AuthCode
		);
	//撤回消息 Auth=180
	CQAPI(CQ_deleteMsg, 整数型)(
		整数型 AuthCode,
		长整数型 MsgId
		);

	//9.20添加

	//是否支持发送图片，返回大于 0 为支持，等于 0 为不支持
	CQAPI(CQ_canSendImage, 整数型)(
		整数型 AuthCode
		);
	//是否支持发送语音，返回大于 0 为支持，等于 0 为不支持
	CQAPI(CQ_canSendRecord, 整数型)(
		整数型 AuthCode
		);
	//接收图片，并返回图片文件绝对路径
	CQAPI(CQ_getImage, 文本型)(
		整数型 AuthCode,
		文本型 file//收到消息中的图片文件名(file)
		);
	//接收语音
	CQAPI(CQ_getRecordV2, 文本型)(
		整数型 AuthCode,
		文本型 file,//收到消息中的语音文件名(file)
		文本型 outformat//应用所需的格式
		);

	//9.25添加

	//取好友列表 Auth=162
	CQAPI(CQ_getFriendList, 文本型)(
		整数型 AuthCode,
		逻辑型 reserved//保留,请始终为 假
		);

	//取群信息(支持缓存) Auth=132
	CQAPI(CQ_getGroupInfo, 文本型)(
		整数型 AuthCode,
		长整数型 群号,//目标群
		逻辑型 不使用缓存
		);
	//取Cookies Auth=20 
	//慎用,此接口需要严格授权
	CQAPI(CQ_getCookiesV2, 文本型)(
		整数型 AuthCode,
		文本型 domain//目标域名，如 api.example.com
		);
}
	//弃用借口放置处
	//
	//取Cookies (慎用，此接口需要严格授权)
	//Auth=20 慎用,此接口需要严格授权
	//CQAPI(CQ_getCookies, 文本型)(
	//	整数型 AuthCode
	//	);
	//
	//接收语音
	//CQAPI(CQ_getRecord, 文本型)(
	//	整数型 AuthCode,
	//	文本型 file,// 收到消息中的语音文件名 (file)
	//	文本型 outformat// 应用所需的格式  mp3,amr,wma,m4a,spx,ogg,wav,flac
	//	);
	//
	//发送赞 Auth=110
	//CQAPI(CQ_sendLike, 整数型)(
	//	整数型 AuthCode,
	//	长整数型 AccountID// 目标账号
	//	);
	//
	//置群添加请求 Auth=151
	//CQAPI(CQ_setGroupAddRequest, 整数型)(
	//	整数型 AuthCode,
	//	文本型 请求反馈标识,// 请求事件收到的“反馈标识”参数
	//	整数型 请求类型,// 根据请求事件的子类型区分 #请求_群添加 或 #请求_群邀请
	//	整数型 反馈类型// #请求_通过 或 #请求_拒绝
	//	);
	//
	//取群成员信息 (旧版,请用CQ_getGroupMemberInfoV2) Auth=130
	//CQAPI(CQ_getGroupMemberInfo, 文本型)(
	//	整数型 AuthCode,
	//	长整数型 群号,// 目标账号所在群
	//	长整数型 AccountID// 目标账号
	//	);