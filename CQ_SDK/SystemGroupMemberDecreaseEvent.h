#pragma once
#include "BasicEvent.h"

inline
namespace CQ {
    struct SystemGroupMemberDecreaseEvent :public BasicEvent {

        int subType;// �����ͣ�1 / ����� 2 / ������
        int sendTime;// ����ʱ��(ʱ���)
        long long fromGroup;// ��ԴȺ��
        long long fromAccount;// �������ʺ�
        long long beingOperateAccount;// �������ʺ�(��ΪȫȺ���� / ������򱾲���Ϊ 0)

        SystemGroupMemberDecreaseEvent(int subType, int sendTime, long long fromGroup, long long fromAccount, long long beingOperateAccount);
    };
}
