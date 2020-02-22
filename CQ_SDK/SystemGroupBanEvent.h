#pragma once
#include "BasicEvent.h"

inline
namespace CQ {
    struct SystemGroupBanEvent :public BasicEvent {

        int subType;// 子类型，1 / 被解禁 2 / 被禁言
        int sendTime;// 发送时间(时间戳)
        long long fromGroup;// 来源群号
        long long fromAccount;// 操作者帐号
        long long beingOperateAccount;// 被操作帐号(若为全群禁言 / 解禁，则本参数为 0)
        long long duration;// 禁言时长(单位 秒，仅子类型为2时可用)

        SystemGroupBanEvent(int subType, int sendTime, long long fromGroup, long long fromAccount, long long beingOperateAccount, long long duration);
    };
}
