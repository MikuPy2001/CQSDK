#pragma once
#include "Base.h"
#include <string>

inline
namespace CQ {
	// İ������Ϣ
	class StrangerInfo
	{
	public:
		�������� QQID;
		std::string nick;//�ǳ�
		������ sex;//0/���� 1/Ů�� 255/δ֪
		������ age;//����

		StrangerInfo(std::string msg);
		StrangerInfo() = default;

		std::string tostring() const;
	};

}