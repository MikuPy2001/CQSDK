#include "toolWin.h"
#include <Windows.h>
#include <Memoryapi.h>

bool CQFree(�ı��� s)
{
	auto heap = GetProcessHeap();
	return HeapFree(heap, NULL, (void*)s);
}

bool CQStringCanRead(�ı��� s)
{
	return s > 0;
}