//��Ӧ���ȿ�appmain

//��δ��ɵ�����
 
 
#include <CQSDK.h>

EVE_Request_AddFriend_EX(Request_AddFriend_EX) {
	
}
EVE_Friend_Add_EX(Friend_Add_EX) {
	
}
EVE_Request_AddGroup_EX(Request_AddGroup_EX) {
	
}
EVE_System_GroupAdmin_EX(System_GroupAdmin_EX) {

}



EVE_GroupUpload(GroupUpload) {
	return 0;
}
EVE_System_GroupMemberDecrease(System_GroupMemberDecrease) {
	return 0;
}
EVE_System_GroupMemberIncrease(System_GroupMemberIncrease) {
	return 0;
}

//ʹ�ÿ�Qԭ���Դ���������Ϣ����
EVE_GroupMsg_EX(GroupMsg_regex)
//name:������Ϣ
//priority:30000
//regex-key:QQ
//regex-key:action
//regex-expression:^(?<action>\S{1,4}?)\s*(?<qq>\d{5,10})\s*?$
{ 
	auto reg = e.regexMsg();
	auto QQ = reg["QQ"];
	auto action = reg["action"];
	e.sendMsg() << code::at(e.fromQQ) << " " << action << "��" << code::at(QQ) << "һ��" << send;
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