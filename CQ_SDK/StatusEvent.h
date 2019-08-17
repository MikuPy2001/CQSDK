#pragma once
#include <string>

inline
namespace CQ {
	struct StatusEvent
	{
		std::string
			//数据
			data="***",
			//数据单位
			dataf="错误";
		int
			// 1 : 绿
			// 2 : 橙
			// 3 : 红
			// 4 : 深红
			// 5 : 黑
			// 6 : 灰
			color=3;
		// 1 : 绿
		void color_green();
		// 2 : 橙
		void color_orange();
		// 3 : 红
		void color_red();
		// 4 : 深红
		void color_crimson();
		// 5 : 黑
		void color_black();
		// 6 : 灰
		void color_gray();
	};
	std::string statusEVEreturn(StatusEvent & eve);
}