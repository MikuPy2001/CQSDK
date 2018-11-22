#include "DiscussMsgEvent.h"

#include "API.h"

MsgSend CQ::DiscussMsgEvent::sendMsg() const { return MsgSend(fromQQ, msgtype::ÌÖÂÛ×é); }

int CQ::DiscussMsgEvent::sendMsg(const char * msg) const { return sendDiscussMsg(fromDiscuss, msg); }
int CQ::DiscussMsgEvent::sendMsg(std::string msg) const { return sendDiscussMsg(fromDiscuss, msg); }

CQ::DiscussMsgEvent::DiscussMsgEvent(int subType, int msgId, long long fromDiscuss, long long fromQQ, const char * msg, int font)
	:MsgEvent(subType, msgId, fromQQ, msg, font), fromDiscuss(fromDiscuss) 
{}

bool CQ::DiscussMsgEvent::leave() const { return !setDiscussLeave(fromDiscuss); }
