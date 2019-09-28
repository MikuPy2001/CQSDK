#include "tool.h"

#include "Unpack.h"

#include <ctype.h>   // for isalnum
#include <string>


using namespace std;

//打印内存数据
string dump(void*t, int len)
{
	string s;
	auto p = static_cast<unsigned char*>(t);
	s += "{";
	for (auto i = 0; i < len; ++i)
	{
		s += to_string(static_cast<int>(p[i]));
		if (i + 1 < len)s += ", ";
	}
	return s += "}";
}

//代码来源于网络
static const string base64_chars =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";

static bool is_base64(unsigned char c) {
	return (isalnum(c) || (c == '+') || (c == '/'));
}

string base64_encode(string const& decode_string) {
	auto in_len = decode_string.size();
	auto bytes_to_encode = decode_string.data();
	string ret;
	int i = 0;
	int j = 0;
	unsigned char char_array_3[3];
	unsigned char char_array_4[4];

	while (in_len--) {
		char_array_3[i++] = *(bytes_to_encode++);
		if (i == 3) {
			char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
			char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
			char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
			char_array_4[3] = char_array_3[2] & 0x3f;

			for (i = 0; (i < 4); i++)
				ret += base64_chars[char_array_4[i]];
			i = 0;
		}
	}

	if (i)
	{
		for (j = i; j < 3; j++)
			char_array_3[j] = '\0';

		char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
		char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
		char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
		char_array_4[3] = char_array_3[2] & 0x3f;

		for (j = 0; (j < i + 1); j++)
			ret += base64_chars[char_array_4[j]];

		while (i++ < 3)
			ret += '=';
	}

	return ret;
}

string base64_decode(string const& encoded_string) {
	int in_len = encoded_string.size();
	int i = 0;
	int j = 0;
	int in_ = 0;
	unsigned char char_array_4[4], char_array_3[3];
	string ret;

	while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
		char_array_4[i++] = encoded_string[in_]; in_++;
		if (i == 4) {
			for (i = 0; i < 4; i++)
				char_array_4[i] = (unsigned char)base64_chars.find(char_array_4[i]);

			char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
			char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
			char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

			for (i = 0; (i < 3); i++)
				ret += char_array_3[i];
			i = 0;
		}
	}

	if (i) {
		for (j = i; j < 4; j++)
			char_array_4[j] = 0;

		for (j = 0; j < 4; j++)
			char_array_4[j] = (unsigned char)base64_chars.find(char_array_4[j]);

		char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
		char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
		char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

		for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
	}

	return ret;
}

std::string&msg_tihuan(std::string  & s, std::string const old, std::string const n)
{
	size_t st = 0;
	while ((st = s.find(old, st)) < s.size()) {
		s.replace(st, old.size(), n); st += n.size();
	}
	return s;
}

std::string & msg_encode(std::string & s, bool isCQ)
{
	msg_tihuan(s, "&", "&amp;");
	msg_tihuan(s, "[", "&#91;");
	msg_tihuan(s, "]", "&#93;");
	msg_tihuan(s, "\t", "&#44;");
	if (isCQ)
		msg_tihuan(s, ",", "&#44;");
	return s;
}

std::string & msg_decode(std::string  & s, bool isCQ)
{
	if (isCQ)
		msg_tihuan(s, "&#44;", ",");
	msg_tihuan(s, "&#91;", "[");
	msg_tihuan(s, "&#93;", "]");
	msg_tihuan(s, "&#44;", "\t");
	msg_tihuan(s, "&amp;", "&");
	return s;
}

std::map<std::string, std::string> regexMsg2Map(std::string msg)
{
	std::map<std::string, std::string> regexMap;
	Unpack msgs(base64_decode(msg));
	auto len = msgs.getInt();//获取参数数量
	while (len-- > 0) {
		auto tep = msgs.getUnpack();
		auto key = tep.getstring();
		auto value = tep.getstring();
		if (key == "") {
			break;//已经意外到结尾了
		}
		regexMap[key] = value;
	}
	return regexMap;
}

