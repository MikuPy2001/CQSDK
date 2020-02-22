#include "GroupUploadEvent.h"
#include "Unpack.h"
#include "tool.h"

CQ::GroupUploadEvent::GroupUploadEvent(int subType, int sendTime, long long fromGroup, long long fromAccount, const char* file)
	:subType(subType), sendTime(sendTime), fromGroup(fromGroup),  fromAccount(fromAccount)
{
    Unpack u(base64_decode(file));
    �ļ�_ID = u.getstring();
    �ļ�_���� = u.getstring();
    �ļ�_��С = u.getLong();
    �ļ�_busid = (int)u.getLong();
}
