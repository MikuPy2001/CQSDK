#pragma once
#include "Base.h"
#include "Unpack.h"
#include <string>

inline
namespace CQ {
	// 群信息
	class GroupInfo
	{
	public:
		长整数型 群号;
		std::string 名称;
		整数型 当前人数;
		整数型 人数上限;

		GroupInfo();
		GroupInfo(Unpack);

		std::string tostring() const;
	};
}