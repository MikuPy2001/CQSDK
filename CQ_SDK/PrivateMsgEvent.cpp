#include "PrivateMsgEvent.h"
#include "API.h"

CQ::PrivateMsgEvent::PrivateMsgEvent(int subType, int msgId, long long fromAccount, const char * msg, int font)
	: MsgEvent(subType, msgId, fromAccount, msg, font) {}

//���Ժ���
bool CQ::PrivateMsgEvent::fromPrivate() const { return subType == 11; }

//��������״̬
bool CQ::PrivateMsgEvent::fromOnlineStatus() const { return subType == 1; }

//����Ⱥ��ʱ
bool CQ::PrivateMsgEvent::fromGroup() const { return subType == 2; }

//������������ʱ
bool CQ::PrivateMsgEvent::fromDiscuss() const { return subType == 3; }

MsgSend CQ::PrivateMsgEvent::sendMsg() const { return MsgSend(fromAccount, msgtype::����); }

int CQ::PrivateMsgEvent::sendMsg(const char * msg) const { return sendPrivateMsg(fromAccount, msg); }
int CQ::PrivateMsgEvent::sendMsg(std::string msg) const { return sendPrivateMsg(fromAccount, msg); }