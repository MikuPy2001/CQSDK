#include "SystemGroupBanEvent.h"

CQ::SystemGroupBanEvent::SystemGroupBanEvent(int subType, int sendTime, long long fromGroup, long long fromAccount, long long beingOperateAccount, long long duration)
	:subType(subType), sendTime(sendTime), fromGroup(fromGroup),  fromAccount(fromAccount), beingOperateAccount(beingOperateAccount), duration(duration)
{
}
