#pragma once
/*
CoolQ SDK for VS2017
Api Version 9.10
Written by MukiPy2001 & Thanks for the help of orzFly and Coxxs
*/
#pragma once

#define CQAPIVER 9
#define CQAPIVERTEXT "9"

typedef int CQBOOL;
typedef int 整数型;
typedef long long 长整数型;
typedef const char* 文本型;
typedef int 逻辑型;


#define CQAPI(NAME,ReturnType) extern "C" __declspec(dllimport) ReturnType __stdcall NAME


#define CQEVENT(ReturnType, Name, Size) __pragma(comment(linker, "/EXPORT:" #Name "=_" #Name "@" #Size))\
	extern "C" __declspec(dllexport) ReturnType __stdcall Name

