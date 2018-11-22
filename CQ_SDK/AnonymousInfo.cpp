#include "AnonymousInfo.h"

#include "Unpack.h"
#include "tool.h"


AnonymousInfo::AnonymousInfo(const char* msg)
{
	if (msg == nullptr || msg[0] == '\0')
	{
		AID = 0; ���� = "";
	}
	else {
		Unpack p(base64_decode(msg));
		AID = p.getLong();
		���� = p.getstring();
		//Token = p.getchars();
	}
}