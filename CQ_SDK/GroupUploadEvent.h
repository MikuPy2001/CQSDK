#pragma once
#include "BasicEvent.h"

#include <string>

inline
namespace CQ {
    struct GroupUploadEvent :public BasicEvent {

        int subType;// 子类型，1 / 被解禁 2 / 被禁言
        int sendTime;// 发送时间(时间戳)
        long long fromGroup;// 来源群号
        long long fromAccount;// 操作者帐号


        std::string 文件_ID;
        std::string 文件_名称;
        long long 文件_大小;
        int 文件_busid;

        GroupUploadEvent(int subType, int sendTime, long long fromGroup, long long fromAccount, const char* file);
    };
}
