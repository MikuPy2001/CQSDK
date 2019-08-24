#pragma once

#include <string>
#include <map>

inline
namespace CQ {
	//正则消息
	class regexMsg {
		//消息
		std::map<std::string, std::string> regexMap;
	public:
		regexMsg(std::string msg);
		std::string get(std::string);
		std::string operator [](std::string);
	};
}