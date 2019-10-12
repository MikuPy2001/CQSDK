#pragma once

#include "RequestBasicEvent.h"

inline
namespace CQ {
	struct RequestAddFriendEvent :public RequestBasicEvent
	{
		RequestAddFriendEvent(int subType, int sendTime, long long fromAccount, const char* msg, const char* responseFlag);
		//通过此请求,并拦截消息
		void pass(std::string msg = "")override;
		//拒绝此请求,并拦截消息
		void fail(std::string msg = "您由于不满足某些要求被拒绝!") override;

	private:
		//子类型
		//1:固定为1
		int subType;
	};
}