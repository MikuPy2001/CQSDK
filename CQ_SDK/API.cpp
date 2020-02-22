#include "API.h"
#include "toolWin.h"

#include "BaseAPI.h"
#include "AuthCode.h"
#include "tool.h"

#include <string>

using namespace std;

int lasterr;
string CQtoString(文本型 data, string API描述);

//增加运行日志
//优先级为LOG_开头的常量
整数型 CQ::addLog(整数型 LOG_, 文本型 类型, 文本型 内容) { return lasterr = CQ_addLog(getAuthCode(), LOG_, 类型, 内容); }

//发送好友消息
整数型 CQ::sendPrivateMsg(长整数型 Account, 文本型 msg) { return  CQ_sendPrivateMsg(getAuthCode(), Account, msg); }

//发送好友消息
整数型 CQ::sendPrivateMsg(长整数型 Account, std::string & msg) { return sendPrivateMsg(Account, msg.c_str()); }

//发送好友消息
//整数型 CQ::sendPrivateMsg(EVEPrivateMsg eve, std::string msg) { return sendPrivateMsg(eve.fromAccount, msg.c_str()); }

//发送群消息
整数型 CQ::sendGroupMsg(长整数型 群号, 文本型 msg) { return  CQ_sendGroupMsg(getAuthCode(), 群号, msg); }

//发送群消息
整数型 CQ::sendGroupMsg(长整数型 群号, std::string & msg) { return sendGroupMsg(群号, msg.c_str()); }

整数型 CQ::sendDiscussMsg(长整数型 讨论组号, 文本型 msg) { return   CQ_sendDiscussMsg(getAuthCode(), 讨论组号, msg); }

//发送讨论组消息
整数型 CQ::sendDiscussMsg(长整数型 讨论组号, std::string & msg) { return sendDiscussMsg(讨论组号, msg.c_str()); }

//发送赞
整数型 CQ::sendLike(长整数型 AccountID, 整数型 times) { return lasterr = CQ_sendLikeV2(getAuthCode(), AccountID, times); }

//取Cookies (慎用，此接口需要严格授权)
string CQ::getCookies(string domain) { return CQtoString(CQ_getCookiesV2(getAuthCode(), domain.c_str	()), "取Cookies"); }

//接收语音
文本型 CQ::getRecord(文本型 file, 文本型 outformat) { return CQ_getRecordV2(getAuthCode(), file, outformat); }

//接收语音
std::string CQ::getRecord(std::string & file, std::string outformat) { return CQtoString(getRecord(file.c_str(), outformat.c_str()), "接收语音"); }

//取CsrfToken (慎用，此接口需要严格授权)
整数型 CQ::getCsrfToken() { return  CQ_getCsrfToken(getAuthCode()); }

//取应用目录
string CQ::getAppDirectory() { return CQtoString(CQ_getAppDirectory(getAuthCode()), "取应用目录"); }

//取登录账号
长整数型 CQ::getLoginQQ() { return getLoginAccount(); }

//取登录昵称
string CQ::getLoginNick() { return CQtoString(CQ_getLoginNick(getAuthCode()), "取登录昵称"); }

//置群员移除
整数型 CQ::setGroupKick(长整数型 群号, 长整数型 AccountID, 逻辑型 拒绝再加群) { return lasterr = CQ_setGroupKick(getAuthCode(), 群号, AccountID, 拒绝再加群); }

//置群员禁言
整数型 CQ::setGroupBan(长整数型 群号, 长整数型 AccountID, 长整数型 禁言时间) { return lasterr = CQ_setGroupBan(getAuthCode(), 群号, AccountID, 禁言时间); }

//置群管理员
整数型 CQ::setGroupAdmin(长整数型 群号, 长整数型 AccountID, 逻辑型 成为管理员) { return lasterr = CQ_setGroupAdmin(getAuthCode(), 群号, AccountID, 成为管理员); }

//置群成员专属头衔
整数型 CQ::setGroupSpecialTitle(长整数型 群号, 长整数型 AccountID, 文本型 头衔, 长整数型 过期时间) { return lasterr = CQ_setGroupSpecialTitle(getAuthCode(), 群号, AccountID, 头衔, 过期时间); }

//置群成员专属头衔
整数型 CQ::setGroupSpecialTitle(长整数型 群号, 长整数型 AccountID, std::string & 头衔, 长整数型 过期时间) { return setGroupSpecialTitle(群号, AccountID, 头衔.c_str(), 过期时间); }

//置全群禁言
整数型 CQ::setGroupWholeBan(长整数型 群号, 逻辑型 开启禁言) { return lasterr = CQ_setGroupWholeBan(getAuthCode(), 群号, 开启禁言); }

//置匿名群员禁言
整数型 CQ::setGroupAnonymousBan(长整数型 群号, 文本型 匿名, 长整数型 禁言时间) { return lasterr = CQ_setGroupAnonymousBan(getAuthCode(), 群号, 匿名, 禁言时间); }

//置群匿名设置
整数型 CQ::setGroupAnonymous(长整数型 群号, 逻辑型 开启匿名) { return lasterr = CQ_setGroupAnonymous(getAuthCode(), 群号, 开启匿名); }

//置群成员名片
整数型 CQ::setGroupCard(长整数型 群号, 长整数型 AccountID, 文本型 新名片_昵称) { return lasterr = CQ_setGroupCard(getAuthCode(), 群号, AccountID, 新名片_昵称); }

//置群成员名片
整数型 CQ::setGroupCard(长整数型 群号, 长整数型 AccountID, std::string 新名片_昵称) { return setGroupCard(群号, AccountID, 新名片_昵称.c_str()); }

//置群退出
整数型 CQ::setGroupLeave(长整数型 群号, 逻辑型 是否解散) { return lasterr = CQ_setGroupLeave(getAuthCode(), 群号, 是否解散); }

//置讨论组退出
整数型 CQ::setDiscussLeave(长整数型 讨论组号) { return lasterr = CQ_setDiscussLeave(getAuthCode(), 讨论组号); }

//置好友添加请求
整数型 CQ::setFriendAddRequest(文本型 请求反馈标识, 整数型 反馈类型, 文本型 备注) { return lasterr = CQ_setFriendAddRequest(getAuthCode(), 请求反馈标识, 反馈类型, 备注); }

//置群添加请求
整数型 CQ::setGroupAddRequest(文本型 请求反馈标识, 整数型 请求类型, 整数型 反馈类型, 文本型 理由) { return lasterr = CQ_setGroupAddRequestV2(getAuthCode(), 请求反馈标识, 请求类型, 反馈类型, 理由); }

//置致命错误提示
整数型 CQ::setFatal(文本型 错误信息) { return lasterr = CQ_setFatal(getAuthCode(), 错误信息); }

//取群成员信息 (支持缓存)
GroupMemberInfo CQ::getGroupMemberInfo(长整数型 群号, 长整数型 AccountID, 逻辑型 不使用缓存) { return GroupMemberInfo(CQtoString(CQ_getGroupMemberInfoV2(getAuthCode(), 群号, AccountID, 不使用缓存), "取群成员信息")); }

//取陌生人信息 (支持缓存)
StrangerInfo CQ::getStrangerInfo(长整数型 AccountID, 逻辑型 不使用缓存) { return StrangerInfo(CQtoString(CQ_getStrangerInfo(getAuthCode(), AccountID, 不使用缓存), "取陌生人信息")); }

//取群成员列表
std::vector<GroupMemberInfo> CQ::getGroupMemberList(长整数型 群号) {
	auto data = CQtoString(CQ_getGroupMemberList(getAuthCode(), 群号), "取群成员列表");
	if (data.empty()) {
		string log = string("API(取群成员列表)返回空数据,群号:") + to_string(群号);
		addLog(Log_Debug, "CQSDK(CPP)", log.c_str());
		return vector<GroupMemberInfo>();
	}

	vector<GroupMemberInfo> infovector;

	Unpack u(base64_decode(data));
	auto len = u.getInt();
	int len1 = 0;
	while (u.len() > 0)
	{
		//infovector.push_back(GroupMemberInfo(u.getchars()));
		infovector.emplace_back(u.getUnpack());
		len1++;
	}
	if (len1 != len) {
		string log = "取群成员列表数量异常, 群号:" + to_string(群号) + " 期望:" + to_string(len) + ",实际:" + to_string(len1);
		addLog(Log_Debug, "CQSDK(CPP)", log.c_str());
	}

	return infovector;
}

//取群列表
std::map<long long, std::string> CQ::getGroupList() {
	auto source = CQtoString(CQ_getGroupList(getAuthCode()), "取群列表"); // 获取原始数据
	if (source.empty()) {
		string log = string("API(取群列表)返回空数据");
		addLog(Log_Debug, "CQSDK(CPP)", log.c_str());
		return map<long long, std::string>();
	}

	string data(base64_decode(source)); // 解码
	Unpack pack(data);// 转换为Unpack

	int len = pack.getInt();//获取总群数
	int len1 = 0;
	std::map<long long, std::string> ret;
	while (pack.len() > 0) {//如果还有剩余数据,就继续读取
		auto tep = pack.getUnpack();//读取下一个群
		long long ID = tep.getLong();//读取群号
		string name = tep.getstring();//读取群名称
		ret[ID] = name;//写入map
		len1++;
	}
	if (len1 != len) {
		string log = "API(取群列表)数据异常, 期望:" + to_string(len) + ",实际:" + to_string(len1);
		addLog(Log_Debug, "CQSDK(CPP)", log.c_str());
	}

	return ret;
}

整数型 CQ::deleteMsg(长整数型 MsgId)
{
	return lasterr = CQ_deleteMsg(getAuthCode(), MsgId);
}

//其他不重要的函数
string CQtoString(文本型 data, string API描述) {
	if (CQStringCanRead(data)) {
		return data;
	}
	string log = API描述 + "时发生异常,API返回指针为负数: " + to_string((int)data);
	addLog(Log_Debug, "CQSDK(CPP)", log.c_str());
	return "";
}

const char* CQ::getlasterrmsg()
{
	switch (lasterr)
	{
	case 0:    return "操作成功"; case -1:   return "请求发送失败"; case -2:   return "未收到服务器回复，可能未发送成功"; case -3:   return "消息过长或为空"; case -4:   return "消息解析过程异常"; case -5:   return "日志功能未启用"; case -6:   return "日志优先级错误"; case -7:   return "数据入库失败"; case -8:   return "不支持对系统帐号操作"; case -9:   return "帐号不在该群内，消息无法发送"; case -10:  return "该用户不存在/不在群内"; case -11:  return "数据错误，无法请求发送"; case -12:  return "不支持对匿名成员解除禁言"; case -13:  return "无法解析要禁言的匿名成员数据"; case -14:  return "由于未知原因，操作失败"; case -15:  return "群未开启匿名发言功能，或匿名帐号被禁言"; case -16:  return "帐号不在群内或网络错误，无法退出/解散该群"; case -17:  return "帐号为群主，无法退出该群"; case -18:  return "帐号非群主，无法解散该群"; case -19:  return "临时消息已失效或未建立"; case -20:  return "参数错误"; case -21:  return "临时消息已失效或未建立"; case -22:  return "获取账号信息失败"; case -23:  return "找不到与目标账号的关系，消息无法发送"; case -99:  return "您调用的功能无法在此版本上实现"; case -101: return "应用过大"; case -102: return "不是合法的应用"; case -103: return "不是合法的应用"; case -104: return "应用不存在公开的Information函数"; case -105: return "无法载入应用信息"; case -106: return "文件名与应用ID不同"; case -107: return "返回信息解析错误"; case -108: return "AppInfo返回的Api版本不支持直接加载，仅支持Api版本为9(及以上)的应用直接加载"; case -109: return "AppInfo返回的AppID错误"; case -110: return "缺失AppInfo返回的AppID对应的[Appid].json文件"; case -111: return "[Appid].json文件内的AppID与其文件名不同"; case -120: return "无Api授权接收函数(Initialize)"; case -121: return "Api授权接收函数(Initialize)返回值非0"; case -122: return "尝试恶意修改酷Q配置文件，将取消加载并关闭酷Q"; case -150: return "无法载入应用信息"; case -151: return "应用信息Json串解析失败，请检查Json串是否正确"; case -152: return "Api版本过旧或过新"; case -153: return "应用信息错误或存在缺失"; case -154: return "Appid不合法"; case -160: return "事件类型(Type)错误或缺失"; case -161: return "事件函数(Function)错误或缺失"; case -162: return "应用优先级不为10000、20000、30000、40000中的一个"; case -163: return "事件类型(Api)不支持应用Api版本"; case -164: return "应用Api版本大于8，但使用了新版本已停用的事件类型(Type)：1(好友消息)、3(临时消息)"; case -165: return "事件类型为2(群消息)、4(讨论组消息)、21(私聊消息)，但缺少正则表达式(regex)的表达式部分(expression)"; case -166: return "存在为空的正则表达式(regex)的key"; case -167: return "存在为空的正则表达式(regex)的表达式部分(expression)"; case -168: return "应用事件(event)id参数不存在或为0"; case -169: return "应用事件(event)id参数有重复"; case -180: return "应用状态(status)id参数不存在或为0"; case -181: return "应用状态(status)period参数不存在或设置错误"; case -182: return "应用状态(status)id参数有重复"; case -201: return "无法载入应用，可能是应用文件已损坏"; case -202: return "Api版本过旧或过新"; case -997: return "应用未启用"; case -998: return "应用调用在Auth声明之外的 酷Q Api。";      	default:   return "未知错误,请向 初音Py2001 报告以升级SDK";
	}
}

// 9.20
bool CQ::canSendImage()
{
	return CQ_canSendImage(getAuthCode()) > 0;
}

bool CQ::canSendRecord()
{
	return CQ_canSendRecord(getAuthCode()) > 0;
}

string CQ::getImage(string file)
{
	return CQtoString(CQ_getImage(getAuthCode(), file.c_str()), "接收图片");
}

// 9.25
std::vector<FriendInfo> CQ::getFriendList()
{
	//其他_转换_文本到好友列表信息a
	auto data = CQtoString(CQ_getFriendList(getAuthCode(),false), "取好友列表");
	if (data.empty()) {
		string log = string("API(取好友列表)返回空数据");
		addLog(Log_Debug, "CQSDK(CPP)", log.c_str());
		return vector<FriendInfo>();
	}

	vector<FriendInfo> infovector;

	Unpack u(base64_decode(data));
	auto len = u.getInt();
	int len1 = 0;
	while (u.len() > 0)
	{
		//其他_转换_ansihex到好友信息
		infovector.emplace_back(u.getUnpack());
		len1++;
	}
	if (len1 != len) {
		string log = "API(取好友列表)数据异常, 期望:" + to_string(len) + ",实际:" + to_string(len1);
		addLog(Log_Debug, "CQSDK(CPP)", log.c_str());
	}

	return infovector;
}

GroupInfo CQ::getGroupInfo(长整数型 群号, 逻辑型 不使用缓存)
{
	auto data = CQtoString(CQ_getGroupInfo(getAuthCode(), 群号, 不使用缓存), "取群信息");
	if (data.empty()) {
		string log = string("API(取群信息)返回空数据");
		addLog(Log_Debug, "CQSDK(CPP)", log.c_str());
		return GroupInfo();
	}
	return GroupInfo(Unpack(base64_decode(data)));
}

长整数型 CQ::getLoginAccount() { return  CQ_getLoginQQ(getAuthCode()); }
