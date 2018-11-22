#include "RequestAddFriendEvent.h"

#include "API.h"

CQ::RequestAddFriendEvent::RequestAddFriendEvent(int subType, int sendTime, long long fromQQ, const char * msg, const char * responseFlag)
	: RequestBasicEvent(sendTime, fromQQ, msg, responseFlag), subType(subType)
{}

void CQ::RequestAddFriendEvent::pass(std::string msg)
{
	setFriendAddRequest(responseFlag, ����_ͨ��, msg.c_str());
}
void CQ::RequestAddFriendEvent::fail(std::string msg)
{
	setFriendAddRequest(responseFlag, ����_�ܾ�, msg.c_str());
}