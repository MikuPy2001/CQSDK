#pragma once
#include "Base.h"
#include <vector>
#include <string>


//base64����
std::string base64_encode(std::string const& s);

//base64����
std::string base64_decode(std::string const& s);

//�滻
std::string & msg_tihuan(std::string & s, std::string const old, std::string const New);

//CQcode����
std::string & msg_encode(std::string & s, bool isCQ = false);

//CQcode����
std::string & msg_decode(std::string & s, bool isCQ = false);

//���Ƶ�������ֽڼ�
std::string dump(void*t, int len);

//��ȡcpu��������������..
inline unsigned __int64 GetCycleCount()
{
	__asm _emit 0x0F
	__asm _emit 0x31
}
