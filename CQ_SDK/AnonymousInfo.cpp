#include "AnonymousInfo.h"

#include "Unpack.h"
#include "tool.h"


AnonymousInfo::AnonymousInfo(const char* msg)
{
	if (msg == nullptr || msg[0] == '\0')
	{
		AID = 0; ´úºÅ = "";
	}
	else {
		Unpack p(base64_decode(msg));
		AID = p.getLong();
		´úºÅ = p.getstring();
		//Token = p.getchars();
	}
}