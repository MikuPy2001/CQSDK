#pragma once

#include "RequestBasicEvent.h"

inline
namespace CQ {
	struct RequestAddFriendEvent :public RequestBasicEvent
	{
		RequestAddFriendEvent(int subType, int sendTime, long long fromQQ, const char* msg, const char* responseFlag);
		//ͨ��������,��������Ϣ
		void pass(std::string msg = "")override;
		//�ܾ�������,��������Ϣ
		void fail(std::string msg = "�����ڲ�����ĳЩҪ�󱻾ܾ�!") override;

	private:
		//������
		//1:�̶�Ϊ1
		int subType;
	};
}