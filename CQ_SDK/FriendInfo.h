#pragma once
#include "Base.h"
#include "Unpack.h"
#include <string>

inline
namespace CQ {
	// 好友信息
	class FriendInfo
	{
	public:
		长整数型 AccountID;
		std::string nick;//昵称
		std::string remark;//备注

		FriendInfo() = default;
		FriendInfo(Unpack u);

		std::string tostring() const;
	};

}