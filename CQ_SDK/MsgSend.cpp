#include "MsgSend.h"

#include "API.h"
#include "Logger.h"

CQ::MsgSend::MsgSend(long long ID, msgtype Type)
	: ID(ID), subType(Type)
{}

CQ::MsgSend::MsgSend(long long ID, int Type)
	: ID(ID), subType(Type)
{}

void CQ::MsgSend::SEND() {
	if (buf.size() <= 0)return;
	switch (subType)
	{
	case msgtype::����:
		sendPrivateMsg(ID, buf);
		break;
	case msgtype::Ⱥ:
		sendGroupMsg(ID, buf);
		break;
	case msgtype::������:
		sendDiscussMsg(ID, buf);
		break;
	default:
		static Logger log("�쳣����");
		log.Warning()
			<< "��Ϣ�����쳣"
			<< ",���:" << ID
			<< ",ԭ��: " << buf
			<< send;
		break;
	}
}