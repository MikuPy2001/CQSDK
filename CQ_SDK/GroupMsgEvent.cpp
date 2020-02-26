#include "GroupMsgEvent.h"

#include "API.h"
#include "code.h"

using namespace std;


CQ::GroupMsgEvent::GroupMsgEvent(int subType, int msgId, long long fromGroup, long long fromAccount, const char * fromAnonymous, const char * msg, int font)
	:MsgEvent(subType, msgId, fromAccount, msg, font), fromGroup(fromGroup), fromAnonymousToken(fromAnonymous), fromAnonymousInfo()
{}

CQ::GroupMsgEvent::~GroupMsgEvent()
{
	if (fromAnonymousInfo != nullptr)
		delete fromAnonymousInfo;
}

bool CQ::GroupMsgEvent::isAnonymous() const { return fromAccount == 80000000; }

AnonymousInfo & CQ::GroupMsgEvent::getFromAnonymousInfo() //throw(std::exception_ptr)
{
	if (isAnonymous())
		return
		fromAnonymousInfo != nullptr
		? *fromAnonymousInfo
		: *(fromAnonymousInfo = new AnonymousInfo(fromAnonymousToken));
	else
		throw std::exception_ptr();
}

bool CQ::GroupMsgEvent::setGroupKick(bool refusedAddAgain)
{
	return !CQ::setGroupKick(fromGroup, fromAccount, refusedAddAgain);
}

bool CQ::GroupMsgEvent::setGroupBan(long long banTime)
{
	if (isAnonymous()) {
		return !CQ::setGroupAnonymousBan(fromGroup, fromAnonymousToken, banTime);
	}
	else {
		return !CQ::setGroupBan(fromGroup, fromAccount, banTime);
	}
}

bool CQ::GroupMsgEvent::setGroupAdmin(bool isAdmin)
{
	return !CQ::setGroupAdmin(fromGroup, fromAccount, isAdmin);
}

bool CQ::GroupMsgEvent::setGroupSpecialTitle(std::string ר��ͷ��, long long ����ʱ��)
{
	return !CQ::setGroupSpecialTitle(fromGroup, fromAccount, ר��ͷ��, ����ʱ��);
}

bool CQ::GroupMsgEvent::setGroupWholeBan(bool ��������)
{
	return CQ::setGroupWholeBan(fromGroup, ��������);
}

bool CQ::GroupMsgEvent::setGroupAnonymous(bool ��������)
{
	return CQ::setGroupAnonymous(fromGroup, ��������);
}

bool CQ::GroupMsgEvent::setGroupCard(std::string ����Ƭ_�ǳ�)
{
	return CQ::setGroupCard(fromGroup, fromAccount, ����Ƭ_�ǳ�);
}

bool CQ::GroupMsgEvent::setGroupLeave(bool �Ƿ��ɢ)
{
	return CQ::setGroupLeave(fromGroup, �Ƿ��ɢ);
}

GroupMemberInfo CQ::GroupMsgEvent::getGroupMemberInfo(bool ��ʹ�û���)
{
	return CQ::getGroupMemberInfo(fromGroup, fromAccount, ��ʹ�û���);
}

std::vector<GroupMemberInfo> CQ::GroupMsgEvent::getGroupMemberList()
{
	return CQ::getGroupMemberList(fromGroup);
}
int CQ::GroupMsgEvent::sendMsg(const char * msg) const { return sendGroupMsg(fromGroup, msg); }
int CQ::GroupMsgEvent::sendMsg(std::string msg) const { return sendGroupMsg(fromGroup, msg); }
MsgSend CQ::GroupMsgEvent::sendMsg()const { return MsgSend(fromGroup, msgtype::Ⱥ); }

int CQ::GroupMsgEvent::sendMsg(const char* msg, bool at_user) const { return sendMsg(string(msg), at_user); }
int CQ::GroupMsgEvent::sendMsg(std::string msg, bool at_user) const { return at_user ? sendMsg(code::at(fromAccount) + msg) : sendMsg(msg); }
MsgSend CQ::GroupMsgEvent::sendMsg(bool at_user) const { auto res = sendMsg(); if (at_user) res << code::at(fromAccount); return res; }
