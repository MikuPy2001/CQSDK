#include "GroupInfo.h"

using namespace std;

CQ::GroupInfo::GroupInfo(Unpack u)
{
	群号 = u.getLong();
	名称 = u.getstring();
	当前人数 = u.getInt();
	人数上限 = u.getInt();
}

CQ::GroupInfo::GroupInfo():	群号(0),名称(""),当前人数(0),人数上限 (0)
{
}

std::string CQ::GroupInfo::tostring() const
{
	return
		string()
		+ "{群号: " + to_string(群号)
		+ ",名称: " + 名称
		+ ",当前人数: " + to_string(当前人数)
		+ ",人数上限: " + to_string(人数上限)
		+ "}"
		;
}
