#include "MsgEvent.h"


CQ::MsgEvent::MsgEvent(int subType, int msgId, long long fromQQ, const char* message, int font)
	: subType(subType), msgId(msgId), fromQQ(fromQQ), message(message), messageRAW((char*)message), font(font)
{}

//真实用户
bool CQ::MsgEvent::isUser() const
{
	switch (fromQQ)
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
	return fromQQ == 1000000;
}