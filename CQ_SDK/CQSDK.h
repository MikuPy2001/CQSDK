#pragma once

//第一层头文件,不依赖任何非项目头文件
#include "AuthCode.h"
#include "Base.h"
#include "BaseStream.h"
#include "event.h"
#include "face.h"
//#include "regexMsg.h"
#include "StatusEvent.h"
#include "SystemGroupAdminEvent.h"
#include "Unpack.h"
#include "toolWin.h"

//第二层头文件,部分依赖第一层头文件
#include "AnonymousInfo.h"
#include "BaseAPI.h"
#include "BasicEvent.h"
#include "code.h"
#include "GroupMemberInfo.h"
#include "LogStream.h"
#include "MsgSend.h"
#include "StrangerInfo.h"
#include "StrangerInfo.h"
#include "tool.h"

//第三层,同上
#include "API.h"
#include "FriendAddEvent.h"
#include "GroupUploadEvent.h"
#include "MsgEvent.h"
#include "RequestBasicEvent.h"
#include "SystemGroupMemberDecreaseEvent.h"
#include "SystemGroupMemberIncreaseEvent.h"
#include "SystemGroupAdminEvent.h"
#include "SystemGroupBanEvent.h" //9.25新增


//第四层,同上
#include "DiscussMsgEvent.h"
#include "GroupMsgEvent.h"
#include "Logger.h"
#include "PrivateMsgEvent.h"
#include "RequestAddFriendEvent.h"
#include "RequestAddGroupEvent.h"


#ifdef CQDEBUG
#include "debug.h"
#endif // DEBUG