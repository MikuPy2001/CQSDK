#include "DiscussMsgEvent.h"

#include "API.h"

MsgSend CQ::DiscussMsgEvent::sendMsg() const { return MsgSend(fromAccount, msgtype::ÌÖÂÛ×é); }

int CQ::DiscussMsgEvent::sendMsg(const char * msg) const { return sendDiscussMsg(fromDiscuss, msg); }
int CQ::DiscussMsgEvent::sendMsg(std::string msg) const { return sendDiscussMsg(fromDiscuss, msg); }

CQ::DiscussMsgEvent::DiscussMsgEvent(int subType, int msgId, long long fromDiscuss, long long fromAccount, const char * msg, int font)
	:MsgEvent(subType, msgId, fromAccount, msg, font), fromDiscuss(fromDiscuss) 
{}

bool CQ::DiscussMsgEvent::leave() const { return !setDiscussLeave(fromDiscuss); }
