//��Ӧ���ȿ�appmain

//��δ��ɵ�����


#include <CQSDK.h>
#include <string>
using namespace std;

EVE_Request_AddFriend_EX(Request_AddFriend_EX) {}
EVE_Friend_Add_EX(Friend_Add_EX) {}
EVE_Request_AddGroup_EX(Request_AddGroup_EX) {}
EVE_System_GroupAdmin_EX(System_GroupAdmin_EX) {}

EVE_GroupUpload_EX(GroupUpload_EX) {}
EVE_System_GroupMemberDecrease_EX(System_GroupMemberDecrease_EX) {}
EVE_System_GroupMemberIncrease_EX(System_GroupMemberIncrease_EX) {}



static Logger logger("Ⱥ�����¼�");
EVE_System_GroupBan_EX(System_GroupBan_EX)
//name:������Ϣ
//priority:30000
{
	auto debug = logger.Debug();


	auto gInfo = getGroupInfo(e.fromGroup);
	debug << "[" << gInfo.���� << "]��";

	if (e.beingOperateAccount == 0) {
		debug << "[ȫ��]";
	}
	else {
		auto qInfo = getGroupMemberInfo(e.fromGroup, e.beingOperateAccount);
		debug << "[" << qInfo.��Ƭ << "(" << e.beingOperateAccount << ")]";
	}

	auto qInfo = getGroupMemberInfo(e.fromGroup, e.fromAccount);
	debug << "��[" << gInfo.���� << "(" << e.fromAccount << ")]";

	switch (e.subType)
	{
	case 1:
		debug << "�������" ;
		break;
	case 2:
		debug << "����" << e.duration << "��";
		break;
	default:
		debug << "������δ֪����(" << e.subType << ")";
		break;
	}
	debug << send;
}



EVE_Status_EX(Status)
//name:CPUʹ����
//title:CPU
//period:1000
/*
name:�ڲ˵���ʾ������
title:������������ʾ������
period:��������(����)
*/
{
	e.data = "����";
	e.dataf = "����";
	e.color_red();
	//ÿ�ε��ö���������������������
}

void xxx(char*, char*);
EVE_Menu_EX(menuA)
//name:����A
{
	xxx("�˵���ť�����", "����A");
}