#include "MsgEvent.h"
#include "Tool.h"


CQ::MsgEvent::MsgEvent(int subType, int msgId, long long fromAccount, const char* message, int font)
	: subType(subType), msgId(msgId), fromAccount(fromAccount), message(message), messageRAW((char*)message), font(font)
{}

//真实用户
bool CQ::MsgEvent::isUser() const
{
	switch (fromAccount)
	{
	case 1000000:// 系统提示
	case 80000000:// 匿名
		return false;
	default:
		return true;
	}
}
bool CQ::MsgEvent::isSystem() const
{
	return fromAccount == 1000000;
}

std::map<std::string, std::string> CQ::MsgEvent::regexMsg()
{
	return regexMsg2Map(this->message);
}
