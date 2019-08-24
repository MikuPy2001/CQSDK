#pragma once
#include "Base.h"
#include <vector>
#include <string>
#include <map>


//base64编码
std::string base64_encode(std::string const& s);

//base64解码
std::string base64_decode(std::string const& s);

//替换
std::string & msg_tihuan(std::string & s, std::string const old, std::string const New);

//CQcode编码
std::string & msg_encode(std::string & s, bool isCQ = false);

//CQcode解码
std::string & msg_decode(std::string & s, bool isCQ = false);

//CQregexMsg消息提取
std::map<std::string, std::string> regexMsg2Map(std::string msg);

//类似调试输出字节集
std::string dump(void*t, int len);

//获取cpu启动后经历的周期..
inline unsigned __int64 GetCycleCount()
{
	__asm _emit 0x0F
	__asm _emit 0x31
}
