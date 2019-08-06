//您应当先看appmain

//此文件讲述如何监听回复消息

#include <CQSDK.h>
#include <string>
using namespace std;

//请加上static,表示这个logger只有本cpp有效
static Logger logger("Msg_EX");


//所有EX版事件默认拥有一个e参数,事件相关参数被包装到e参数中,通过ide快速补全
void Msg(MsgEvent*e);


EVE_GroupMsg_EX(GroupMsg_EX)
//name:群聊消息
//priority:30000
{
	auto debug = logger.Debug();
	debug << DEBUGINFO << e.message;
	if (e.isAnonymous()) {//判断是否为匿名信息
		auto info = e.getFromAnonymousInfo();//获取匿名信息
		debug << ", 匿名者代号为:" << info.代号 << e.message << endl;//输出到日志
	}

	//获取群成员列表
	//auto list = e.getGroupMemberList();

	//遍历群成员
	//for each (auto var in list){
	//	logger.Debug() << var.tostring() << e.message<<endl;

	//获取群成员信息
	//auto QQInfo = list[e.fromQQ];
	//logger.Debug() << QQInfo.tostring() << endl;



	//取发言者的群信息
	//auto player=e.getGroupMemberInfo();
	//	logger.Debug() << player.tostring() << e.message;

	//开启群匿名
	//e.setGroupAnonymous(true);

	//把这个人置为管理员
	//e.setGroupAdmin(true);

	//设置禁言,默认1分钟
	//e.setGroupBan();

	//e.setGroupSpecialTitle("群头衔");
	//e.setGroupCard("群名片");
	//e.setGroupKick();//干掉这个人

	debug << send;//发送日志
	Msg(&e);
}
EVE_PrivateMsg_EX(PrivateMsg_EX)
//name:私聊消息
//priority:30000
{
	logger.Debug() << DEBUGINFO << e.message;
	Msg(&e);
}
EVE_DiscussMsg_EX(DiscussMsg_EX)
//name:讨论组
//priority:30000
{
	logger.Debug() << DEBUGINFO << e.message;
	Msg(&e);
}



void Msg(MsgEvent*e) 
{

	// 获得一个和事件有关的消息对象
	// 这个消息对象已经自动关联事件对应的群或者好友
	auto msg = e->sendMsg();
	// 如果你想给特定的人发送消息,例如好友123456
	// 您可以直接调用API
	//sendPrivateMsg(123456, "你好");
	// 或者使用MsgSend
	//MsgSend P123456(123456, msgtype::好友);
	//P123456 << "你好" << send;

	auto message = e->message;

	// 普通的发送一条消息
	if (!message.compare("CQ:msg1"))
		e->sendMsg("收到消息了!");

	// 使用<<来发送消息
	if (!message.compare("CQ:msg2"))
		//一定要末尾加上<<send才会发送出去
		msg << "收到消息了!" << send;

	// 强大的消息发送方式
	if (!message.compare("CQ:msg3"))
		// 发送内容由多个内容组成
		msg
		<< "发送人为:" << e->fromQQ
		<< ",消息为:" << e->message
		<< send;

	if (!message.compare("CQ:image")) {
		logger.Debug() << "raw模式:" << msg.isRAW() << send;
		// 发送一个图片
		msg << code::image("123.gif") << send;
	}

	if (!message.compare("CQ:face"))
		//发送一个表情
		msg << code::face(face::得意) << send;

	if (!message.compare("CQ:raw"))
		msg
		// RAW 表示后面的消息将被原样发送
		// 而不是解析成CQ码,并调用特有功能,例如发送图片
		<< RAW << code::at(e->fromQQ)
		// CODE 表示后面的消息将被解析为CQ码
		// 默认解析
		<< CODE << code::face(face::得意)
		<< send;

	if (!message.compare("CQ:effect"))
		// 发送一个魔法字体,此CQ码必须单独一条消息
		e->sendMsg(code::effect("art", 2003, "魔法消息"));
	if (!message.compare("CQ:at"))
		// 发送at消息,在私聊时是无效的
		msg << code::at(e->fromQQ) << send;
}