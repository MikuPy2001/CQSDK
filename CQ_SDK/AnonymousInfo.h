#pragma once

#include "Base.h"

#include <string>

inline
namespace CQ {
	// Ⱥ������Ϣ
	struct AnonymousInfo
	{
		�������� AID;
		std::string ����;
		//std::vector<unsigned char> Token;

		AnonymousInfo(const char* fromAnonymousToken);
		AnonymousInfo() = default;
	};
}