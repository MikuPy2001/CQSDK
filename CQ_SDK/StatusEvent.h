#pragma once
#include <string>

inline
namespace CQ {
	struct StatusEvent
	{
		std::string
			//����
			data="***",
			//���ݵ�λ
			dataf="����";
		int
			// 1 : ��
			// 2 : ��
			// 3 : ��
			// 4 : ���
			// 5 : ��
			// 6 : ��
			color=3;
		// 1 : ��
		void color_green();
		// 2 : ��
		void color_orange();
		// 3 : ��
		void color_red();
		// 4 : ���
		void color_crimson();
		// 5 : ��
		void color_black();
		// 6 : ��
		void color_gray();
	};
	std::string statusEVEreturn(StatusEvent & eve);
}