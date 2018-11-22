#pragma once

#include "MsgEvent.h"

inline
namespace CQ {
	struct DiscussMsgEvent :public MsgEvent
	{
		long long fromDiscuss;//�������

		DiscussMsgEvent(int subType, int msgId, long long fromDiscuss, long long fromQQ, const char* msg, int font);

		//�˳�������
		bool leave() const;

		// ͨ�� MsgEvent �̳�
		virtual MsgSend sendMsg() const override;
		virtual int sendMsg(const char *) const override;
		virtual int sendMsg(std::string) const override;
	};
}