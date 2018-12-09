#pragma once

#include "Base.h"

inline
namespace CQ {
	struct Font {
		文本型 名称;
		整数型 字号,
			颜色,
			/*粗体：1 斜体：2 下划线：4*/
			样式,
			气泡;

		explicit Font(int);
	};
}