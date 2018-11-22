#pragma once

#include "BaseStream.h"

#include <string>

inline
namespace CQ
{
	enum msgtype { 好友, 群, 讨论组 };
	class MsgSend : public BaseStream
	{
		long long ID;
		int subType;

	public:
		/*
		Type:
		0=msgtype::好友
		1=msgtype::群
		2=msgtype::讨论组
		*/
		MsgSend(long long GroupID_Or_QQID, msgtype Type);
		/*
		Type:
		0=好友
		1=群
		2=讨论组
		*/
		MsgSend(long long GroupID_Or_QQID, int Type);

		virtual void SEND() override;
	};
}