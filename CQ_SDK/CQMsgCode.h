#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
//#include <shared_mutex>

namespace CQ {
	//cq消息参数
	struct OneCodeMsg { size_t key, keylen = 0, value = 0; OneCodeMsg(size_t key); };
	//一条cq消息或者普通消息
	struct CodeMsg : std::vector<OneCodeMsg> { public: bool isCode; size_t key, keylen = 0; CodeMsg(bool isCode, size_t key); };

	class MsgCode;
	struct CodeMsgsFor {
		MsgCode&t;
		size_t pos;
		CQ::MsgCode&operator*();
		CQ::CodeMsgsFor&operator++();
		bool operator!=(CQ::CodeMsgsFor&);
		CodeMsgsFor(MsgCode&t, int pos);
	};
	//消息解析
	class MsgCode {
		std::vector<CodeMsg> msglist;
		std::string txt;
		size_t thismsg = 0;//指针
		void decod();//解码
		bool find(std::string &s, int);
		bool is(std::string &s, int);
	public:
		MsgCode(std::string);

		//定位到指定段
		CQ::MsgCode&operator[](size_t);
		CQ::MsgCode&operator++(int);
		CQ::MsgCode&operator++();
		CQ::MsgCode&operator--(int);
		CQ::MsgCode&operator--();
		CQ::MsgCode&operator-(size_t);
		CQ::MsgCode&operator+(size_t);
		//返回指针当前位置
		int pos();

		//从当前位置开始搜索指定cq码
		//如果存在,定位到指定段
		//否则返回null,并且不会移动指针
		bool find(std::string s);

		//从当前位置开始反向搜索指定cq码
		//如果存在,定位到指定段
		//否则返回null,并且不会移动指针
		bool lastfind(std::string);

		//判断是否是CQ码
		bool isCQcode();

		//判断是否为指定CQ码
		bool is(std::string);

		//如果是CQ码,返回CQ码类型
		//如果不是,返回消息
		std::string get();

		//如果是CQ码,返回键对应的值
		//如果找不到键,则返回空字符
		//如果不是,返回空字符
		std::string get(std::string key);
		std::vector<std::string> keys();

		CQ::CodeMsgsFor begin();
		CQ::CodeMsgsFor end();

		void debug();
	};

	
}