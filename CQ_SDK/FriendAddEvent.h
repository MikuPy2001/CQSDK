#pragma once

#include "BasicEvent.h"

inline
namespace CQ {
	struct FriendAddEvent :public BasicEvent {
		int sendTime; //����ʱ��
		long long fromQQ;//������ѵĺ�
		FriendAddEvent(int subType, int sendTime, long long fromQQ);
	private:
		int subType; //�̶�Ϊ1
	};
}