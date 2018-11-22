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
		RequestAddGroupEvent(int subType, int sendTime, long long fromGroup, long long fromQQ, const char* msg, const char* responseFlag);
		//ͨ��������
		void pass(std::string msg = "")override;
		//�ܾ�������
		void fail(std::string msg = "�����ڲ�����ĳЩҪ�󱻾ܾ�!") override;
	};
}