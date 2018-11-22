#pragma once

#include "BaseStream.h"

#include <string>

inline
namespace CQ
{
	enum msgtype { ����, Ⱥ, ������ };
	class MsgSend : public BaseStream
	{
		long long ID;
		int subType;

	public:
		/*
		Type:
		0=msgtype::����
		1=msgtype::Ⱥ
		2=msgtype::������
		*/
		MsgSend(long long GroupID_Or_QQID, msgtype Type);
		/*
		Type:
		0=����
		1=Ⱥ
		2=������
		*/
		MsgSend(long long GroupID_Or_QQID, int Type);

		virtual void SEND() override;
	};
}