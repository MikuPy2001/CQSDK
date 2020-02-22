#pragma once
#include "BasicEvent.h"

inline
namespace CQ {
	struct SystemGroupAdminEvent :public BasicEvent {
		int subType;//子类型，1 / 被取消管理员 2 / 被设置管理员
		int sendTime;//发送时间(时间戳)
		long long fromGroup;//来源群号
		long long beingOperateAccount;//被操作账号

		SystemGroupAdminEvent(int subType, int sendTime, long long fromGroup, long long beingOperateAccount);
	};
}
