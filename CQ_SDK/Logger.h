#pragma once

#include "LogStream.h"

#include <string>

#define DEBUGINFO "[文件:" << __FILE__ << ",行数:" << __LINE__ << "]输出:"

inline
namespace CQ
{
	class Logger
	{
		std::string title;
	public:
		Logger(std::string title);
		void setTitle(std::string title);

		void Debug(const char* msg)const;
		void Debug(std::string&msg)const;

		void Error(const char* msg)const;
		void Error(std::string&msg)const;

		void Fatal(const char* msg)const;
		void Fatal(std::string&msg)const;

		void Info(const char* msg)const;
		void Info(std::string&msg)const;

		void InfoRecv(const char* msg)const;
		void InfoRecv(std::string&msg)const;

		void InfoSend(const char* msg)const;
		void InfoSend(std::string&msg)const;

		void InfoSuccess(const char* msg)const;
		void InfoSuccess(std::string&msg)const;

		void Warning(const char* msg)const;
		void Warning(std::string&msg)const;


		LogStream Debug()const;
		LogStream Info()const;
		LogStream InfoSuccess()const;
		LogStream InfoRecv()const;
		LogStream InfoSend()const;
		LogStream Warning()const;
		LogStream Error()const;
		LogStream Fatal()const;
	};
}