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
typedef int ������;
typedef long long ��������;
typedef const char* �ı���;
typedef int �߼���;


#define CQAPI(NAME,ReturnType) extern "C" __declspec(dllimport) ReturnType __stdcall NAME


#define CQEVENT(ReturnType, Name, Size) __pragma(comment(linker, "/EXPORT:" #Name "=_" #Name "@" #Size))\
	extern "C" __declspec(dllexport) ReturnType __stdcall Name

