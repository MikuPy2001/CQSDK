#pragma once
#include "BasicEvent.h"

inline
namespace CQ {
	struct SystemGroupAdminEvent :public BasicEvent {
		int subType;//�����ͣ�1 / ��ȡ������Ա 2 / �����ù���Ա
		int sendTime;//����ʱ��(ʱ���)
		long long fromGroup;//��ԴȺ��
		long long beingOperateAccount;//�������˺�

		SystemGroupAdminEvent(int subType, int sendTime, long long fromGroup, long long beingOperateAccount);
	};
}
