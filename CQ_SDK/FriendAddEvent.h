#pragma once

#include "BasicEvent.h"

inline
namespace CQ {
	struct FriendAddEvent :public BasicEvent {
		int subType; //�̶�Ϊ1
		int sendTime; //����ʱ��
		long long fromQQ;//������ѵĺ�
		FriendAddEvent(int subType, int sendTime, long long fromQQ);
	};
}