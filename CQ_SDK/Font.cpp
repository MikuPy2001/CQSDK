#include "Font.h"

#include <Windows.h>
Font::Font(int font) 
{
	RtlMoveMemory(static_cast<void*>(this), reinterpret_cast<void *>(font), 20); 
}