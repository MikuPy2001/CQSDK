#pragma once
#include <string>
inline
namespace CQ {
	class BaseStream {
	protected:
		std::string buf;
		bool raw = false;
		friend void RAW(BaseStream & log);
		friend void CODE(BaseStream & log);
	public:
		virtual	bool isRAW();
		virtual void clear();

		//字符串
		virtual	BaseStream & append(const std::string & s);
		virtual	BaseStream & operator <<(const std::string & s);
		//
		virtual	BaseStream & append(const char * c);
		virtual	BaseStream & operator <<(const char * c);

		//整数
		virtual	BaseStream & append(const bool & i);
		virtual	BaseStream & operator <<(const bool & i);
		virtual	BaseStream & append(const int & i);
		virtual	BaseStream & operator <<(const int & i);
		virtual	BaseStream & append(const  size_t & i);
		virtual	BaseStream & operator <<(const size_t & i);
		virtual	BaseStream & append(const double & i);
		virtual	BaseStream & operator <<(const double & i);
		virtual	BaseStream & append(const long & i);
		virtual	BaseStream & operator <<(const long & i);
		virtual	BaseStream & append(const long long & l);
		virtual	BaseStream & operator <<(const long long & l);

		//特殊控制符
		virtual	BaseStream & operator <<(void(*control)(BaseStream &));
		virtual	void SEND() = 0;
		virtual	void FLUSH();

		virtual ~BaseStream();
	};

	//发送并清除缓冲区
	inline void send(BaseStream & log) { log.SEND(); log.clear(); };
	//只发送,保留缓冲区,下次发送时将发送重复内容
	inline void flush(BaseStream & log) { log.FLUSH(); };

	//换行
	inline void endl(BaseStream & log) { log << "\r\n"; };

	//RAW模式输出字符串,忽略酷Q码的含义
	inline void RAW(BaseStream & log) { log.raw = true; };
	//字符串中的酷Q码将生效
	inline void CODE(BaseStream & log) { log.raw = false; };
}