#pragma once

#include "BasicEvent.h"
#include <string>

inline
namespace CQ {
	struct RequestBasicEvent :public BasicEvent
	{
		int sendTime; // ����ʱ��(ʱ���)
		long long fromQQ; // ��ԴQQ
		const char* msg; // ����
		const char* responseFlag;// ������ʶ(����������)

		RequestBasicEvent(int sendTime, long long fromQQ, const char* msg, const char* responseFlag);
		//ͨ��������
		virtual void pass(std::string msg) = 0;
		//�ܾ�������
		virtual	void fail(std::string msg) = 0;
	};
}