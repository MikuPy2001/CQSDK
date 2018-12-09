#pragma once

#include "BasicEvent.h"

inline
namespace CQ {
	struct FriendAddEvent :public BasicEvent {
		int sendTime; //发送时间
		long long fromQQ;//加你好友的号
		FriendAddEvent(int subType, int sendTime, long long fromQQ);
	private:
		int subType; //固定为1
	};
}