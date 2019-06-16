#pragma once
//相关实现依赖具体平台:Window
//可重写本实现以移植其他平台
#include "Base.h"

//释放CQ传来的字符串内存
bool CQFree(文本型);

//检查CQ传来的字符串指针是否可读
bool CQStringCanRead(文本型);