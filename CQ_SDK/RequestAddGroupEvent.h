#pragma once

#include "RequestBasicEvent.h"

inline
namespace CQ {
	struct RequestAddGroupEvent :public RequestBasicEvent
	{
		//子类型
		//1:他人申请入群
		//2:自己(即登录号)受邀入群
		int subType;
		long long fromGroup; // 来源群号
		RequestAddGroupEvent(int subType, int sendTime, long long fromGroup, long long fromAccount, const char* msg, const char* responseFlag);
		//通过此请求,并拦截消息
		void pass(std::string msg = "")override;
		//拒绝此请求,并拦截消息
		void fail(std::string msg = "您由于不满足某些要求被拒绝!") override;
	};
}