#include "RequestBasicEvent.h"

CQ::RequestBasicEvent::RequestBasicEvent(int sendTime, long long fromQQ, const char * msg, const char * responseFlag)
	: sendTime(sendTime), fromQQ(fromQQ), msg(msg), responseFlag(responseFlag)
{}