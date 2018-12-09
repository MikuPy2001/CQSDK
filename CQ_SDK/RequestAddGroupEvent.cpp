#include "RequestAddGroupEvent.h"

#include "API.h"

CQ::RequestAddGroupEvent::RequestAddGroupEvent(int subType, int sendTime, long long fromGroup, long long fromQQ, const char * msg, const char * responseFlag)
	: RequestBasicEvent(sendTime, fromQQ, msg, responseFlag), subType(subType), fromGroup(fromGroup)
{}

void CQ::RequestAddGroupEvent::pass(std::string msg)
{
	setGroupAddRequest(responseFlag, subType, ����_ͨ��, msg.c_str());
	message_block();
}

void CQ::RequestAddGroupEvent::fail(std::string msg)
{
	setGroupAddRequest(responseFlag, subType, ����_�ܾ�, msg.c_str());
	message_block();
}

