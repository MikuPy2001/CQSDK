#include "Unpack.h"

using namespace std;

//�ڴ淭ת
unsigned char* Flip(unsigned char*str, int len)
{
	int f = 0; --len; unsigned char p;
	while (f < len)
	{
		p = str[len];
		str[len] = str[f];
		str[f] = p;
		++f; --len;
	}
	return str;
}
//���ֽڼ�...
//��ԭ�е����ݻ����ϲ���
template<typename ClassType>
unsigned char * toBin(ClassType & i)
{
	return Flip(reinterpret_cast<unsigned char*>(&i), sizeof(ClassType));
}
//unsigned char * Int2Bin(int&i)
//{
//	return Flip(reinterpret_cast<unsigned char*>(&i), 4);
//}

Unpack& Unpack::setData(const char* i, int len)
{
	buff.assign(i, i + len);
	return *this;
}

Unpack::Unpack() {}

Unpack::Unpack(const char* data)
{
	setData(data, strlen(data));
}

Unpack::Unpack(std::vector<unsigned char> data)
{
	buff = data;
}

Unpack::Unpack(std::string data)
{
	setData(data.data(), data.size());
}

Unpack& Unpack::clear()
{
	buff.clear();
	return *this;
}

int Unpack::len() const
{
	return buff.size();
}

Unpack& Unpack::add(int i)
{
	auto t = toBin<int>(i);
	buff.insert(buff.end(), t, t + sizeof(int));
	return *this;
}

int Unpack::getInt()
{
	auto len = sizeof(int);
	if (buff.size() < len)return 0;

	auto ret = *reinterpret_cast<int*>(Flip(&(buff[0]), len));
	buff.erase(buff.begin(), buff.begin() + len);
	return ret;
}

Unpack& Unpack::add(long long i)
{
	auto t = toBin<long long>(i);
	buff.insert(buff.end(), t, t + sizeof(long long));
	return *this;
}

long long Unpack::getLong()
{
	auto len = sizeof(long long);
	if (buff.size() < len)return 0;

	auto ret = *reinterpret_cast<long long*>(Flip(&(buff[0]), len));
	buff.erase(buff.begin(), buff.begin() + len);
	return ret;
}

Unpack& Unpack::add(short i)
{
	auto t = toBin<short>(i);
	buff.insert(buff.end(), t, t + sizeof(short));
	return *this;
}

short Unpack::getshort()
{
	auto len = sizeof(short);
	if (buff.size() < len)return 0;

	auto ret = *reinterpret_cast<short*>(Flip(&(buff[0]), len));
	buff.erase(buff.begin(), buff.begin() + len);
	return ret;
}

Unpack& Unpack::add(unsigned char* i, short len)
{
	if (len < 0)
		return *this;
	add(len);
	if (len)
		buff.insert(buff.end(), i, i + len);
	return *this;
}

std::vector<unsigned char> Unpack::getchars()
{
	size_t len = getshort();
	if (buff.size() < len)return vector<unsigned char>();

	auto tep = vector<unsigned char>(buff.begin(), buff.begin() + len);
	buff.erase(buff.begin(), buff.begin() + len);
	return tep;
}

Unpack& Unpack::add(string i)
{
	if (i.size() <= 0)//�ַ�������Ϊ0,ֱ�ӷ��볤��0
	{
		add(static_cast<short>(0));
		return *this;
	}
	if (i.size() > 32767)//�ַ������ȳ�������,
	{
		i = i.substr(0, 32767);
	}

	add((unsigned char*)i.data(), (short)i.size());

	return *this;
}

string Unpack::getstring()
{
	auto tep = getchars();
	if (tep.size() == 0)return "";

	tep.push_back(static_cast<char>(0));
	return string(reinterpret_cast<char*>(&tep[0]));
}

Unpack & Unpack::add(Unpack & i)
{
	add(i.getAll());
	return *this;
}

Unpack Unpack::getUnpack() { return Unpack(getchars()); }

std::string Unpack::getAll() {
	string ret;
	for (auto b : buff)
		ret += b;
	return ret;
}

string Unpack::to_string()
{
	string out;	auto len = 0;
	for (auto c : buff) {
		out.append(
			::to_string(static_cast<int>(c))
		).append(", ");
		++len;
	}
	out = ::to_string(len)
		.append("{")
		.append(out.substr(0, out.size() - 2))
		.append("}");
	return out;
}