#pragma once
//相关实现依赖具体平台:Window
//可重写本实现以移植其他平台
#include "Base.h"


inline
namespace CQ {
	//检查CQ传来的字符串指针是否可读
	//此函数还未与平台相关,但是最好使用平台相关的代码进行检查
	bool CQStringCanRead(文本型);
}