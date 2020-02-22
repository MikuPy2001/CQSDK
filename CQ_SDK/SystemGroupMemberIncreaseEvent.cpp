#include "SystemGroupMemberIncreaseEvent.h"

CQ::SystemGroupMemberIncreaseEvent::SystemGroupMemberIncreaseEvent(int subType, int sendTime, long long fromGroup, long long fromAccount, long long beingOperateAccount)
	:subType(subType), sendTime(sendTime), fromGroup(fromGroup),  fromAccount(fromAccount), beingOperateAccount(beingOperateAccount)
{
}
