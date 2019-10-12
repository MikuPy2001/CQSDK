#pragma once

#include "MsgEvent.h"


inline
namespace CQ {
	struct PrivateMsgEvent :public MsgEvent
	{
		PrivateMsgEvent(int subType, int msgId, long long fromAccount, const char* msg, int Font);

		//���Ժ���
		bool fromPrivate() const;

		//��������״̬
		bool fromOnlineStatus() const;

		//����Ⱥ��ʱ
		bool fromGroup() const;

		//������������ʱ
		bool fromDiscuss() const;

		// ͨ�� MsgEvent �̳�
		virtual MsgSend sendMsg() const override;

		virtual int sendMsg(const char *) const override;

		virtual int sendMsg(std::string) const override;
	};
}