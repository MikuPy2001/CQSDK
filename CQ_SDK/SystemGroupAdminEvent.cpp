#include "SystemGroupAdminEvent.h"

CQ::SystemGroupAdminEvent::SystemGroupAdminEvent(int subType, int sendTime, long long fromGroup, long long beingOperateAccount)
	:subType (subType) ,sendTime (sendTime), fromGroup (fromGroup) ,beingOperateAccount (beingOperateAccount)
{
}
