#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>
//#include <shared_mutex>

namespace CQ {
	//cq��Ϣ����
	struct OneCodeMsg { size_t key, keylen = 0, value = 0; OneCodeMsg(size_t key); };
	//һ��cq��Ϣ������ͨ��Ϣ
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
	//��Ϣ����
	class MsgCode {
		std::vector<CodeMsg> msglist;
		std::string txt;
		size_t thismsg = 0;//ָ��
		void decod();//����
		bool find(std::string &s, int);
		bool is(std::string &s, int);
	public:
		MsgCode(std::string);

		//��λ��ָ����
		CQ::MsgCode&operator[](size_t);
		CQ::MsgCode&operator++(int);
		CQ::MsgCode&operator++();
		CQ::MsgCode&operator--(int);
		CQ::MsgCode&operator--();
		CQ::MsgCode&operator-(size_t);
		CQ::MsgCode&operator+(size_t);
		//����ָ�뵱ǰλ��
		int pos();

		//�ӵ�ǰλ�ÿ�ʼ����ָ��cq��
		//�������,��λ��ָ����
		//���򷵻�null,���Ҳ����ƶ�ָ��
		bool find(std::string s);

		//�ӵ�ǰλ�ÿ�ʼ��������ָ��cq��
		//�������,��λ��ָ����
		//���򷵻�null,���Ҳ����ƶ�ָ��
		bool lastfind(std::string);

		//�ж��Ƿ���CQ��
		bool isCQcode();

		//�ж��Ƿ�Ϊָ��CQ��
		bool is(std::string);

		//�����CQ��,����CQ������
		//�������,������Ϣ
		std::string get();

		//�����CQ��,���ؼ���Ӧ��ֵ
		//����Ҳ�����,�򷵻ؿ��ַ�
		//�������,���ؿ��ַ�
		std::string get(std::string key);
		std::vector<std::string> keys();

		CQ::CodeMsgsFor begin();
		CQ::CodeMsgsFor end();

		void debug();
	};

	
}