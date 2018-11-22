#include "SystemGroupAdminEvent.h"

CQ::SystemGroupAdminEvent::SystemGroupAdminEvent(int subType, int sendTime, long long fromGroup, long long beingOperateQQ)
	:subType (subType) ,sendTime (sendTime), fromGroup (fromGroup) ,beingOperateQQ (beingOperateQQ)
{
}
