#include "PrivateMsgEvent.h"
#include "API.h"

CQ::PrivateMsgEvent::PrivateMsgEvent(int subType, int msgId, long long fromAccount, const char * msg, int font)
	: MsgEvent(subType, msgId, fromAccount, msg, font) {}

//来自好友
bool CQ::PrivateMsgEvent::fromPrivate() const { return subType == 11; }

//来自在线状态
bool CQ::PrivateMsgEvent::fromOnlineStatus() const { return subType == 1; }

//来自群临时
bool CQ::PrivateMsgEvent::fromGroup() const { return subType == 2; }

//来自讨论组临时
bool CQ::PrivateMsgEvent::fromDiscuss() const { return subType == 3; }

MsgSend CQ::PrivateMsgEvent::sendMsg() const { return MsgSend(fromAccount, msgtype::好友); }

int CQ::PrivateMsgEvent::sendMsg(const char * msg) const { return sendPrivateMsg(fromAccount, msg); }
int CQ::PrivateMsgEvent::sendMsg(std::string msg) const { return sendPrivateMsg(fromAccount, msg); }