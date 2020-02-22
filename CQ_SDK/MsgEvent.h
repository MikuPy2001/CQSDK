#pragma once

#include "BasicEvent.h"
#include "MsgSend.h"

#include <string>
#include <map>

inline
namespace CQ {
	//消息事件基类
	struct MsgEvent :public BasicEvent
	{
		//消息ID
		int msgId;
		//来源账号
		long long fromAccount;
		//消息
		std::string message;
		char* messageRAW;

		MsgEvent(int subType, int msgId, long long fromAccount, const char* message, int font);

		//真实用户
		bool isUser() const;
		//是否是系统用户
		bool isSystem() const;

		virtual int sendMsg(const char*) const = 0;
		virtual int sendMsg(std::string) const = 0;
		virtual MsgSend sendMsg() const = 0;

		//正则消息获取,未做缓存,请勿多次获取
		virtual std::map<std::string, std::string> regexMsg();
	protected:
		//子类型
		int subType;
		//字体(已经弃用)现为保留变量
		//Font font;
		int font;
	};
}