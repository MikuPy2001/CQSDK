#include "regexMsg.h"

#include "Unpack.h"
#include "tool.h"


CQ::regexMsg::regexMsg(std::string msg)
{
	Unpack msgs(base64_decode(msg));
	auto len = msgs.getInt();//获取参数数量
	while (len-- > 0) {
		auto tep = msgs.getUnpack();
		auto key = tep.getstring();
		auto value = tep.getstring();
		if (key == "") {
			return;
		}
		regexMap[key] = value;
	}
}
std::string CQ::regexMsg::get(std::string key)
{
	return regexMap[key];
}
std::string CQ::regexMsg::operator[](std::string key)
{
	return regexMap[key];
}