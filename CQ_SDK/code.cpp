#include "code.h"

#include "tool.h"


using namespace std;

string CQ::code::image(string file)
{
	return string("[CQ:image,file=") + msg_encode(file, true) + "]";
}

string CQ::code::record(string fileurl, bool magic)
{
	string s = string("[CQ:record,file=") + msg_encode(fileurl, true);
	if (magic)s += ",magic=true";
	return s += "]";
}

//string CQ::code::record(string fileurl, string wantSpeak, bool magic)
//{
//	if (!Speak_to_wav_file(fileurl, wantSpeak))return string("");
//
//	string s = string("[CQ:record,file=") + msg_encode(fileurl, true);
//	if (magic)s += ",magic=true";
//	return s += "]";
//}

string CQ::code::face(int faceid)
{
	return string("[CQ:face,id=") + to_string(faceid) + "]";
}

string CQ::code::face(CQ::face face)
{
	return code::face(static_cast<int>(face));
}

string CQ::code::at(long long Account)
{
	return string("[CQ:at,qq=") + to_string(Account) + "]";
}
std::string CQ::code::at(std::string Account)
{
	return string("[CQ:at,qq=") + Account + "]";
}
string CQ::code::effect(string type, int id, string content)
{
	return string("[CQ:effect,type=") + type + ",id=" + to_string(id) + ",content=" + msg_encode(content, true) + "]";
}

string CQ::code::sign(string title, string imageUrl)
{
	return string("[CQ:sign,title=") + msg_encode(title, true) + ",image=" + msg_encode(imageUrl, true) + "]";
}

string CQ::code::anonymous(bool ignore)
{
	return string(ignore ? "[CQ:anonymous,ignore=true]" : "[CQ:anonymous]");
}