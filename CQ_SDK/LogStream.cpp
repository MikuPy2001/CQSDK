#include "LogStream.h"

#include "API.h"
#include <string>


CQ::LogStream::LogStream(std::string title, int Log_flag)
	: flag(Log_flag), title(title)
{}

void CQ::LogStream::SEND()
{
	if (buf.size() <= 0)
		return;
	addLog(flag, title.c_str(), buf.c_str());
}
