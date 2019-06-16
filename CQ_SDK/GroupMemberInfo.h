#pragma once
#include "Base.h"

#include "Unpack.h"

#include <string>
#include <vector>

inline
namespace CQ {
	// Ⱥ��Ա��Ϣ
	class GroupMemberInfo
	{
		void Void();
		void setdata(Unpack&pack);
	public:
		�������� Group;
		�������� QQID;
		std::string �ǳ�;
		std::string ��Ƭ;
		������ �Ա�; // 0/���� 1/Ů��
		������ ����;
		std::string ����;
		������ ��Ⱥʱ��;
		������ �����;
		std::string �ȼ�_����;
		������ permissions; //1/��Ա 2/����Ա 3/Ⱥ��
		std::string ר��ͷ��;
		������ ר��ͷ�ι���ʱ��; // -1 ��������
		�߼��� ������¼��Ա;
		�߼��� �����޸���Ƭ;

		GroupMemberInfo(Unpack& msg);
		//��API����
		GroupMemberInfo(std::string msg);
		//��Unpack����
		GroupMemberInfo(std::vector<unsigned char> msg);
		GroupMemberInfo() = default;

		std::string tostring() const;
	};
}