#pragma once

#include "BasicEvent.h"
#include <string>

inline
namespace CQ {
	struct RequestBasicEvent :public BasicEvent
	{
		int sendTime; // 发送时间(时间戳)
		long long fromAccount; // 来源账号
		const char* msg; // 附言
		const char* responseFlag;// 反馈标识(处理请求用)

		RequestBasicEvent(int sendTime, long long fromAccount, const char* msg, const char* responseFlag);
		//通过此请求
		virtual void pass(std::string msg) = 0;
		//拒绝此请求
		virtual	void fail(std::string msg) = 0;
	};
}