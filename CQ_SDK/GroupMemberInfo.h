#pragma once
#include "Base.h"

#include "Unpack.h"

#include <string>
#include <vector>

inline
namespace CQ {
	// 群成员信息
	class GroupMemberInfo
	{
		void Void();
		void setdata(Unpack&pack);
	public:
		长整数型 Group;
		长整数型 AccountID;
		std::string 昵称;
		std::string 名片;
		整数型 性别; // 0/男性 1/女性
		整数型 年龄;
		std::string 地区;
		整数型 加群时间;
		整数型 最后发言;
		std::string 等级_名称;
		整数型 permissions; //1/成员 2/管理员 3/群主
		std::string 专属头衔;
		整数型 专属头衔过期时间; // -1 代表不过期
		逻辑型 不良记录成员;
		逻辑型 允许修改名片;

		GroupMemberInfo(Unpack& msg);
		//从API解码
		GroupMemberInfo(std::string msg);
		//从Unpack解码
		GroupMemberInfo(std::vector<unsigned char> msg);
		GroupMemberInfo() = default;

		std::string tostring() const;
	};
}