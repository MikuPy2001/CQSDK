#pragma once

#include "BasicEvent.h"

inline
namespace CQ {
	struct FriendAddEvent :public BasicEvent {
		int sendTime; //����ʱ��
		long long fromAccount;//������ѵĺ�
		FriendAddEvent(int subType, int sendTime, long long fromAccount);
	private:
		int subType; //�̶�Ϊ1
	};
}