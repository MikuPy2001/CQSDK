#include "GroupMemberInfo.h"

#include "tool.h"

using namespace std;



CQ::GroupMemberInfo::GroupMemberInfo(Unpack & msg) {
	setdata(msg);
}

CQ::GroupMemberInfo::GroupMemberInfo(string msg)
{
	if (msg.empty())
	{
		Void();
	}
	else
	{
		Unpack u(base64_decode(msg));
		setdata(u);
		//setdata(Unpack(base64_decode(msg)));
	}
}

CQ::GroupMemberInfo::GroupMemberInfo(vector<unsigned char> data)
{
	if (data.size() == 0)
	{
		Void();
	}
	else
	{
		Unpack u(data);
		setdata(u);
		//setdata(Unpack(base64_decode(msg)));
	}
}

void CQ::GroupMemberInfo::Void()
{
	Group = 0;
	AccountID = 0;
	�ǳ� = "";
	��Ƭ = "";
	�Ա� = 0;
	���� = 0;
	���� = "";
	��Ⱥʱ�� = 0;
	����� = 0;
	�ȼ�_���� = "";
	permissions = 0;
	������¼��Ա = 0;
	ר��ͷ�� = "";
	ר��ͷ�ι���ʱ�� = 0;
	�����޸���Ƭ = 0;
}

void CQ::GroupMemberInfo::setdata(Unpack& u)
{
	Group = u.getLong();
	AccountID = u.getLong();
	�ǳ� = u.getstring();
	��Ƭ = u.getstring();
	�Ա� = u.getInt();
	���� = u.getInt();
	���� = u.getstring();
	��Ⱥʱ�� = u.getInt();
	����� = u.getInt();
	�ȼ�_���� = u.getstring();
	permissions = u.getInt();
	������¼��Ա = u.getInt() == 1;
	ר��ͷ�� = u.getstring();
	ר��ͷ�ι���ʱ�� = u.getInt();
	�����޸���Ƭ = u.getInt() == 1;
}

string CQ::GroupMemberInfo::tostring() const
{
	string s = "{";
	s += "Ⱥ��:"; s += to_string(Group);
	s += " ,AccountID:"; s += to_string(AccountID);
	s += " ,�ǳ�:"; s += �ǳ�;
	s += " ,��Ƭ:"; s += ��Ƭ;
	s += " ,�Ա�:"; s += (
		�Ա� == 1 ? "��" :
		�Ա� == 2 ? "Ů" :
		"δ֪");
	s += " ,����:"; s += to_string(����);
	s += " ,����:"; s += ����;
	s += " ,��Ⱥʱ��:"; s += to_string(��Ⱥʱ��);
	s += " ,�����:"; s += to_string(�����);
	s += " ,�ȼ�_����:"; s += �ȼ�_����;
	s += " ,����Ȩ��:"; s += (
		permissions == 3 ? "Ⱥ��" :
		permissions == 2 ? "����Ա" :
		permissions == 1 ? "ȺԱ" :
		"����"
		);	s += "("; s += to_string(permissions); s += ")";
	s += " ,������¼��Ա:"; s += to_string(������¼��Ա);
	s += " ,ר��ͷ��:"; s += ר��ͷ��;
	s += " ,ר��ͷ�ι���ʱ��:"; s += to_string(ר��ͷ�ι���ʱ��);
	s += " ,�����޸���Ƭ:"; s += to_string(�����޸���Ƭ);
	s += "}"; return s;
}