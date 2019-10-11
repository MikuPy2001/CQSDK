#include "RequestBasicEvent.h"

CQ::RequestBasicEvent::RequestBasicEvent(int sendTime, long long fromAccount, const char * msg, const char * responseFlag)
	: sendTime(sendTime), fromAccount(fromAccount), msg(msg), responseFlag(responseFlag)
{}
