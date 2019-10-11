#pragma once

#include "MsgEvent.h"

inline
namespace CQ {
	struct DiscussMsgEvent :public MsgEvent
	{
		long long fromDiscuss;//讨论组号

		DiscussMsgEvent(int subType, int msgId, long long fromDiscuss, long long fromAccount, const char* msg, int font);

		//退出讨论组
		bool leave() const;

		// 通过 MsgEvent 继承
		virtual MsgSend sendMsg() const override;
		virtual int sendMsg(const char *) const override;
		virtual int sendMsg(std::string) const override;
	};
}