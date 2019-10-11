#include "StrangerInfo.h"

#include "tool.h"
#include "Unpack.h"

using namespace std;

CQ::StrangerInfo::StrangerInfo(string msg)
{
	if (msg.empty())
	{
		AccountID = 0; sex = 255; age = -1; nick = "";
	}
	else {
		Unpack p(base64_decode(msg));
		AccountID = p.getLong();
		nick = p.getstring();
		sex = p.getInt();
		age = p.getInt();
	}
}

string CQ::StrangerInfo::tostring() const
{
	return string("{")
		+ "Account:" + to_string(AccountID)
		+ " ,昵称:" + nick
		+ " ,性别:" + (sex == 255 ? "未知" : sex == 1 ? "男" : "女")
		+ " ,年龄:" + to_string(age)
		+ "}"
		;
}