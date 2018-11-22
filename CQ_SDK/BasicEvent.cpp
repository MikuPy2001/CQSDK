#include "BasicEvent.h"

void CQ::BasicEvent::message_ignore() { _EVEret = 消息_忽略; }
void CQ::BasicEvent::message_block() { _EVEret = 消息_拦截; }