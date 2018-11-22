#pragma once

#include "RequestBasicEvent.h"

inline
namespace CQ {
	struct RequestAddFriendEvent :public RequestBasicEvent
	{
		//������
		//1:�̶�Ϊ1
		int subType;
		// ��ԴȺ��
		long long fromGroup; 
		RequestAddFriendEvent(int subType, int sendTime, long long fromQQ, const char* msg, const char* responseFlag);
		//ͨ��������
		void pass(std::string msg = "")override;
		//�ܾ�������
		void fail(std::string msg = "�����ڲ�����ĳЩҪ�󱻾ܾ�!") override;
	};
}