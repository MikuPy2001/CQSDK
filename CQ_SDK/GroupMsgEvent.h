#pragma once

#include "MsgEvent.h"
#include "AnonymousInfo.h"
#include "GroupMemberInfo.h"

inline
namespace CQ {
	//群事件
	struct GroupMsgEvent :public MsgEvent
	{
	private:
		AnonymousInfo * fromAnonymousInfo;
	public:
		//群号
		long long fromGroup;
		//禁言用的令牌
		const char* fromAnonymousToken;
		GroupMsgEvent(int subType, int msgId, long long fromGroup, long long fromAccount, const char* fromAnonymous, const char* msg, int Font);

		virtual ~GroupMsgEvent();

		bool isAnonymous() const;

		// 通过 MsgEvent 继承
		int sendMsg(const char *) const override;
		int sendMsg(std::string) const override;
		MsgSend sendMsg() const override;
		int sendMsg(const char*,bool at_user) const;
		int sendMsg(std::string, bool at_user) const;
		MsgSend sendMsg(bool at_user) const;

		//获取匿名者信息
		AnonymousInfo&getFromAnonymousInfo() /*throw(std::exception_ptr)*/;

		//置群员移除
		bool setGroupKick(bool refusedAddAgain = false);
		//置群员禁言
		//自动判断是否是匿名
		bool setGroupBan(long long banTime = 60);
		//置群管理员
		bool setGroupAdmin(bool isAdmin);
		//置群成员专属头衔
		bool setGroupSpecialTitle(std::string 专属头衔, long long 过期时间 = -1);

		//置全群禁言
		bool setGroupWholeBan(bool 开启禁言 = true);
		//置群匿名设置
		bool setGroupAnonymous(bool 开启匿名 = true);
		//置群成员名片
		bool setGroupCard(std::string 新名片_昵称);
		//置群退出
		bool setGroupLeave(bool 是否解散 = false);
		//取群成员信息 (支持缓存)
		GroupMemberInfo getGroupMemberInfo(bool 不使用缓存 = false);
		//取群成员列表
		std::vector<GroupMemberInfo> getGroupMemberList();
	};
}