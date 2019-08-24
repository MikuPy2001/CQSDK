#pragma once

#include <string>
#include <map>

inline
namespace CQ {
	//������Ϣ
	class regexMsg {
		//��Ϣ
		std::map<std::string, std::string> regexMap;
	public:
		regexMsg(std::string msg);
		std::string get(std::string);
		std::string operator [](std::string);
	};
}