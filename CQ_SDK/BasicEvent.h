#pragma once

#include "event.h"

inline
namespace CQ {
	// 事件基类
	struct BasicEvent
	{
		//不对消息做任何动作
		//如果之前拦截了消息,这里将重新放行本条消息,函数结束前有效
		void message_ignore();
		//拦截本条消息
		void message_block();

		int _EVEret = 消息_忽略;

		virtual ~BasicEvent() = default;
	};
}