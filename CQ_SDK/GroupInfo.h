#pragma once
#include "Base.h"
#include "Unpack.h"
#include <string>

inline
namespace CQ {
	// Ⱥ��Ϣ
	class GroupInfo
	{
	public:
		�������� Ⱥ��;
		std::string ����;
		������ ��ǰ����;
		������ ��������;

		GroupInfo();
		GroupInfo(Unpack);

		std::string tostring() const;
	};
}