#include "MsgEvent.h"


CQ::MsgEvent::MsgEvent(int subType, int msgId, long long fromQQ, const char* message, int font)
	: subType(subType), msgId(msgId), fromQQ(fromQQ), message(message), messageRAW((char*)message), font(font)
{}

//��ʵ�û�
bool CQ::MsgEvent::isUser() const
{
	switch (fromQQ)
	{
	case 1000000:// ϵͳ��ʾ
	case 80000000:// ����
		return false;
	default:
		return true;
	}
}
bool CQ::MsgEvent::isSystem() const
{
	return fromQQ == 1000000;
}