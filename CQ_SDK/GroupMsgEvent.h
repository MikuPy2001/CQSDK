#pragma once

#include "MsgEvent.h"
#include "AnonymousInfo.h"
#include "GroupMemberInfo.h"

inline
namespace CQ {
	//Ⱥ�¼�
	struct GroupMsgEvent :public MsgEvent
	{
	private:
		AnonymousInfo * fromAnonymousInfo;
	public:
		//Ⱥ��
		long long fromGroup;
		//�����õ�����
		const char* fromAnonymousToken;
		GroupMsgEvent(int subType, int msgId, long long fromGroup, long long fromAccount, const char* fromAnonymous, const char* msg, int Font);

		virtual ~GroupMsgEvent();

		bool isAnonymous() const;

		// ͨ�� MsgEvent �̳�
		int sendMsg(const char *) const override;
		int sendMsg(std::string) const override;
		MsgSend sendMsg() const override;
		int sendMsg(const char*,bool at_user) const;
		int sendMsg(std::string, bool at_user) const;
		MsgSend sendMsg(bool at_user) const;

		//��ȡ��������Ϣ
		AnonymousInfo&getFromAnonymousInfo() /*throw(std::exception_ptr)*/;

		//��ȺԱ�Ƴ�
		bool setGroupKick(bool refusedAddAgain = false);
		//��ȺԱ����
		//�Զ��ж��Ƿ�������
		bool setGroupBan(long long banTime = 60);
		//��Ⱥ����Ա
		bool setGroupAdmin(bool isAdmin);
		//��Ⱥ��Աר��ͷ��
		bool setGroupSpecialTitle(std::string ר��ͷ��, long long ����ʱ�� = -1);

		//��ȫȺ����
		bool setGroupWholeBan(bool �������� = true);
		//��Ⱥ��������
		bool setGroupAnonymous(bool �������� = true);
		//��Ⱥ��Ա��Ƭ
		bool setGroupCard(std::string ����Ƭ_�ǳ�);
		//��Ⱥ�˳�
		bool setGroupLeave(bool �Ƿ��ɢ = false);
		//ȡȺ��Ա��Ϣ (֧�ֻ���)
		GroupMemberInfo getGroupMemberInfo(bool ��ʹ�û��� = false);
		//ȡȺ��Ա�б�
		std::vector<GroupMemberInfo> getGroupMemberList();
	};
}