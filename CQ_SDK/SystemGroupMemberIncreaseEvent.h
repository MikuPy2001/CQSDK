#pragma once
#include "BasicEvent.h"

inline
namespace CQ {
    struct SystemGroupMemberIncreaseEvent :public BasicEvent {

        int subType;// 子类型，1 / 被解禁 2 / 被禁言
        int sendTime;// 发送时间(时间戳)
        long long fromGroup;// 来源群号
        long long fromAccount;// 操作者帐号
        long long beingOperateAccount;// 被操作账号

        SystemGroupMemberIncreaseEvent(int subType, int sendTime, long long fromGroup, long long fromAccount, long long beingOperateAccount);
    };
}
