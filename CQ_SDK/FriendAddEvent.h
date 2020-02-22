#pragma once

#include "BasicEvent.h"

inline
namespace CQ {
	struct FriendAddEvent :public BasicEvent {
		int sendTime; //发送时间
		long long fromAccount;//加你好友的账号
		FriendAddEvent(int subType, int sendTime, long long fromAccount);
	private:
		int subType; //固定为1
	};
}