#pragma once

#include "event.h"

inline
namespace CQ {
	// �¼�����
	struct BasicEvent
	{
		//������Ϣ���κζ���
		//���֮ǰ��������Ϣ,���ｫ���·��б�����Ϣ,��������ǰ��Ч
		void message_ignore();
		//���ر�����Ϣ
		void message_block();

		int _EVEret = ��Ϣ_����;

		virtual ~BasicEvent() = default;
	};
}