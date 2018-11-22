#pragma once
#include "BaseStream.h"

inline
namespace CQ
{
	class LogStream : public BaseStream
	{
		int flag;
		std::string title;
	public:
		LogStream(std::string title, int Log_flag);

		virtual void SEND() override;
	};
}