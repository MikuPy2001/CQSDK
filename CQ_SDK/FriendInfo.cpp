#include "FriendInfo.h"

CQ::FriendInfo::FriendInfo(Unpack u)
{
	AccountID = u.getLong();
	nick = u.getstring();//êÇ³Æ
	remark = u.getstring();//±¸×¢
}
