#include "MsgSend.h"

#include "API.h"
#include "Logger.h"

CQ::MsgSend::MsgSend(long long ID, msgtype Type)
	: ID(ID), subType(Type)
{}

CQ::MsgSend::MsgSend(long long ID, int Type)
	: ID(ID), subType(msgtype(Type))
{}

void CQ::MsgSend::SEND() {
	if (buf.size() <= 0)return;
	switch (subType)
	{
	case msgtype::好友:
		sendPrivateMsg(ID, buf);
		break;
	case msgtype::群:
		sendGroupMsg(ID, buf);
		break;
	case msgtype::讨论组:
		sendDiscussMsg(ID, buf);
		break;
	default:
		static Logger log("异常报告");
		log.Warning()
			<< "消息发送异常"
			<< ",类别:" << ID
			<< ",原文: " << buf
			<< send;
		break;
	}
}