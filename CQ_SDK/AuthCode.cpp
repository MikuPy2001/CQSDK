#include "AuthCode.h"
#include "Base.h"

int AuthCode;
CQEVENT(int, Initialize, 4)(int AuthCode)
{
	::AuthCode = AuthCode;
	return 0;
}
int CQ::getAuthCode()
{
	return AuthCode;
}