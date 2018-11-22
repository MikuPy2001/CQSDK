#pragma once

#include "BasicEvent.h"

inline
namespace CQ {
	struct FriendAddEvent :public BasicEvent {
		int subType; //固定为1
		int sendTime; //发送时间
		long long fromQQ;//加你好友的号
		FriendAddEvent(int subType, int sendTime, long long fromQQ);
	};
}