#pragma once
#include "Base.h"
#include "Unpack.h"
#include <string>

inline
namespace CQ {
	// ������Ϣ
	class FriendInfo
	{
	public:
		�������� AccountID;
		std::string nick;//�ǳ�
		std::string remark;//��ע

		FriendInfo() = default;
		FriendInfo(Unpack u);

		std::string tostring() const;
	};

}