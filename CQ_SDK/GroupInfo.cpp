#include "GroupInfo.h"

using namespace std;

CQ::GroupInfo::GroupInfo(Unpack u)
{
	Ⱥ�� = u.getLong();
	���� = u.getstring();
	��ǰ���� = u.getInt();
	�������� = u.getInt();
}

CQ::GroupInfo::GroupInfo():	Ⱥ��(0),����(""),��ǰ����(0),�������� (0)
{
}

std::string CQ::GroupInfo::tostring() const
{
	return
		string()
		+ "{Ⱥ��: " + to_string(Ⱥ��)
		+ ",����: " + ����
		+ ",��ǰ����: " + to_string(��ǰ����)
		+ ",��������: " + to_string(��������)
		+ "}"
		;
}
