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

EVE_Status_EX(Status){
	e.data = "����";
	e.dataf = "����";
	e.color_red();
}