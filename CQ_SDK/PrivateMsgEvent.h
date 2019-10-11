#pragma once

#include "MsgEvent.h"


inline
namespace CQ {
	struct PrivateMsgEvent :public MsgEvent
	{
		PrivateMsgEvent(int subType, int msgId, long long fromAccount, const char* msg, int Font);

		//来自好友
		bool fromPrivate() const;

		//来自在线状态
		bool fromOnlineStatus() const;

		//来自群临时
		bool fromGroup() const;

		//来自讨论组临时
		bool fromDiscuss() const;

		// 通过 MsgEvent 继承
		virtual MsgSend sendMsg() const override;

		virtual int sendMsg(const char *) const override;

		virtual int sendMsg(std::string) const override;
	};
}