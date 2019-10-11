#include "RequestAddGroupEvent.h"

#include "API.h"

CQ::RequestAddGroupEvent::RequestAddGroupEvent(int subType, int sendTime, long long fromGroup, long long fromAccount, const char * msg, const char * responseFlag)
	: RequestBasicEvent(sendTime, fromAccount, msg, responseFlag), subType(subType), fromGroup(fromGroup)
{}

void CQ::RequestAddGroupEvent::pass(std::string msg)
{
	setGroupAddRequest(responseFlag, subType, 请求_通过, msg.c_str());
	message_block();
}

void CQ::RequestAddGroupEvent::fail(std::string msg)
{
	setGroupAddRequest(responseFlag, subType, 请求_拒绝, msg.c_str());
	message_block();
}

