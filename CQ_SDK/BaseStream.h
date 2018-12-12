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

		//�ַ���
		virtual	BaseStream & append(const std::string & s);
		virtual	BaseStream & operator <<(const std::string & s);
		//
		virtual	BaseStream & append(const char * c);
		virtual	BaseStream & operator <<(const char * c);

		//����
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

		//������Ʒ�
		virtual	BaseStream & operator <<(void(*control)(BaseStream &));
		virtual	void SEND() = 0;
		virtual	void FLUSH();

		virtual ~BaseStream();
	};

	//���Ͳ����������
	inline void send(BaseStream & log) { log.SEND(); log.clear(); };
	//ֻ����,����������,�´η���ʱ�������ظ�����
	inline void flush(BaseStream & log) { log.FLUSH(); };

	//����
	inline void endl(BaseStream & log) { log << "\r\n"; };

	//RAWģʽ����ַ���,���Կ�Q��ĺ���
	inline void RAW(BaseStream & log) { log.raw = true; };
	//�ַ����еĿ�Q�뽫��Ч
	inline void CODE(BaseStream & log) { log.raw = false; };
}