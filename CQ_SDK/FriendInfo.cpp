#include "FriendInfo.h"

CQ::FriendInfo::FriendInfo(Unpack u)
{
	AccountID = u.getLong();
	nick = u.getstring();//�ǳ�
	remark = u.getstring();//��ע
}
