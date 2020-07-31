#pragma once

#include "BaseStream.h"

#include <string>

inline
namespace CQ
{
	enum class msgtype:int { ����, Ⱥ, ������ };
	class MsgSend : public BaseStream
	{
		long long ID;
		msgtype subType;
	public:
		/*
		Type:
		0=msgtype::����
		1=msgtype::Ⱥ
		2=msgtype::������
		*/
		MsgSend(long long GroupID_Or_AccountID, msgtype Type);
		/*
		Type:
		0=����
		1=Ⱥ
		2=������
		*/
		MsgSend(long long GroupID_Or_AccountID, int Type);
		~MsgSend();

		virtual void SEND() override;
	};
}