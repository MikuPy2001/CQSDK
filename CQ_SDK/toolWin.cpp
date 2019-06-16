#include "toolWin.h"
#include <Windows.h>
#include <Memoryapi.h>

bool CQFree(文本型 s)
{
	auto heap = GetProcessHeap();
	return HeapFree(heap, NULL, (void*)s);
}

bool CQStringCanRead(文本型 s)
{
	return s > 0;
}