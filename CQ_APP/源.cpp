//��Ӧ���ȿ�appmain

//��δ��ɵ�����
 
 
#include <CQSDK.h>

EVE_Request_AddFriend_EX(Request_AddFriend_EX) {}
EVE_Friend_Add_EX(Friend_Add_EX) {}
EVE_Request_AddGroup_EX(Request_AddGroup_EX) {}
EVE_System_GroupAdmin_EX(System_GroupAdmin_EX) {}

EVE_GroupUpload_EX(GroupUpload_EX) {}
EVE_System_GroupMemberDecrease_EX(System_GroupMemberDecrease_EX) {}
EVE_System_GroupMemberIncrease_EX(System_GroupMemberIncrease_EX) {}

EVE_System_GroupBan_EX(System_GroupBan_EX) {}

//ʹ�ÿ�Qԭ���Դ���������Ϣ����
EVE_GroupMsg_EX(GroupMsg_regex)
//name:������Ϣ
//priority:30000
//regex-key:Account
//regex-key:action
//regex-expression:^(?<action>\S{1,4}?)\s*(?<Account>\d{5,10})\s*?$
{ 
	auto reg = e.regexMsg();
	auto Account = reg["Account"];
	auto action = reg["action"];
	e.sendMsg() << code::at(e.fromAccount) << " " << action << "��" << code::at(Account) << "һ��" << send;
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

EVE_Menu_EX(menuA)
//name:����A
{

}