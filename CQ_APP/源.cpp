//您应当先看appmain

//还未完成的内容


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



static Logger logger("群禁言事件");
EVE_System_GroupBan_EX(System_GroupBan_EX)
//name:禁言消息
//priority:30000
{
	auto debug = logger.Debug();


	auto gInfo = getGroupInfo(e.fromGroup);
	debug << "[" << gInfo.名称 << "]的";

	if (e.beingOperateAccount == 0) {
		debug << "[全体]";
	}
	else {
		auto qInfo = getGroupMemberInfo(e.fromGroup, e.beingOperateAccount);
		debug << "[" << qInfo.名片 << "(" << e.beingOperateAccount << ")]";
	}

	auto qInfo = getGroupMemberInfo(e.fromGroup, e.fromAccount);
	debug << "被[" << gInfo.名称 << "(" << e.fromAccount << ")]";

	switch (e.subType)
	{
	case 1:
		debug << "解除禁言" ;
		break;
	case 2:
		debug << "禁言" << e.duration << "秒";
		break;
	default:
		debug << "进行了未知操作(" << e.subType << ")";
		break;
	}
	debug << send;
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

void xxx(char*, char*);
EVE_Menu_EX(menuA)
//name:设置A
{
	xxx("菜单按钮被点击", "设置A");
}