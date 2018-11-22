#pragma once

#include "BasicEvent.h"
#include "MsgSend.h"

#include <string>

inline
namespace CQ {
	//消息事件基类
	struct MsgEvent :public BasicEvent
	{
		//子类型
		int subType;
		//消息ID
		int msgId;
		//来源QQ
		long long fromQQ;
		//消息
		std::string message;
		char* messageRAW;
		//字体
		//Font font;
		int font;

		MsgEvent(int subType, int msgId, long long fromQQ, const char* message, int font);

		//真实用户
		bool isUser() const;
		//是否是系统用户
		bool isSystem() const;

		virtual int sendMsg(const char*) const = 0;
		virtual int sendMsg(std::string) const = 0;
		virtual MsgSend sendMsg() const = 0;
	};
}