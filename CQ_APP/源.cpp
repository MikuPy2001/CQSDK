//您应当先看appmain

//还未完成的内容
 
 
#include <CQSDK.h>

EVE_Request_AddFriend_EX(Request_AddFriend_EX) {}
EVE_Friend_Add_EX(Friend_Add_EX) {}
EVE_Request_AddGroup_EX(Request_AddGroup_EX) {}
EVE_System_GroupAdmin_EX(System_GroupAdmin_EX) {}

EVE_GroupUpload_EX(GroupUpload_EX) {}
EVE_System_GroupMemberDecrease_EX(System_GroupMemberDecrease_EX) {}
EVE_System_GroupMemberIncrease_EX(System_GroupMemberIncrease_EX) {}

EVE_System_GroupBan_EX(System_GroupBan_EX) {}

//使用酷Q原生自带的正则消息捕获
EVE_GroupMsg_EX(GroupMsg_regex)
//name:正则消息
//priority:30000
//regex-key:Account
//regex-key:action
//regex-expression:^(?<action>\S{1,4}?)\s*(?<Account>\d{5,10})\s*?$
{ 
	auto reg = e.regexMsg();
	auto Account = reg["Account"];
	auto action = reg["action"];
	e.sendMsg() << code::at(e.fromAccount) << " " << action << "了" << code::at(Account) << "一下" << send;
}

EVE_Status_EX(Status)
//name:CPU使用率
//title:CPU
//period:1000
/*
name:在菜单显示的名字
title:在悬浮窗上显示的文字
period:触发周期(毫秒)
*/
{
	e.data = "标题";
	e.dataf = "数据";
	e.color_red();
	//每次调用都必须设置以上三个数据
}

EVE_Menu_EX(menuA)
//name:设置A
{

}