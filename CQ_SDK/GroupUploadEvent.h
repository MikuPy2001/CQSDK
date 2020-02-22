#pragma once
#include "BasicEvent.h"

#include <string>

inline
namespace CQ {
    struct GroupUploadEvent :public BasicEvent {

        int subType;// �����ͣ�1 / ����� 2 / ������
        int sendTime;// ����ʱ��(ʱ���)
        long long fromGroup;// ��ԴȺ��
        long long fromAccount;// �������ʺ�


        std::string �ļ�_ID;
        std::string �ļ�_����;
        long long �ļ�_��С;
        int �ļ�_busid;

        GroupUploadEvent(int subType, int sendTime, long long fromGroup, long long fromAccount, const char* file);
    };
}
