#pragma once

#include "RequestBasicEvent.h"

inline
namespace CQ {
	struct RequestAddGroupEvent :public RequestBasicEvent
	{
		//������
		//1:����������Ⱥ
		//2:�Լ�(����¼��)������Ⱥ
		int subType;
		long long fromGroup; // ��ԴȺ��
		RequestAddGroupEvent(int subType, int sendTime, long long fromGroup, long long fromAccount, const char* msg, const char* responseFlag);
		//ͨ��������,��������Ϣ
		void pass(std::string msg = "")override;
		//�ܾ�������,��������Ϣ
		void fail(std::string msg = "�����ڲ�����ĳЩҪ�󱻾ܾ�!") override;
	};
}