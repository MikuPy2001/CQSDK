#include "GroupUploadEvent.h"
#include "Unpack.h"
#include "tool.h"

CQ::GroupUploadEvent::GroupUploadEvent(int subType, int sendTime, long long fromGroup, long long fromAccount, const char* file)
	:subType(subType), sendTime(sendTime), fromGroup(fromGroup),  fromAccount(fromAccount)
{
    Unpack u(base64_decode(file));
    文件_ID = u.getstring();
    文件_名称 = u.getstring();
    文件_大小 = u.getLong();
    文件_busid = (int)u.getLong();
}
