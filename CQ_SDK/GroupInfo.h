#pragma once
#include "Base.h"
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

		GroupInfo() = default;

		std::string tostring() const;
	};

}