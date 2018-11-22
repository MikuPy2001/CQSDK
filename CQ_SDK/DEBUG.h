#pragma once

#include <Windows.h>

#define CQTry __try{

#define CQTryEnd(evename,msg) }__except(dump(GetExceptionInformation(),#evename,#msg)){}

int dump(EXCEPTION_POINTERS* ep, const char*evename, const char*msg);