#pragma comment(lib,"CQ_SDK.lib")
#include <CQSDK.h>

//----��ΪʲôҪ�޸����ID----
//�������Ĳ������,һ����һ�޶�������

//----��Ӧ������޸����ID----
//������Ӧ���޸��·���CQAPPID
//Ȼ���޸���Ŀ����      (����ָ��VSʹ��������������ļ�)
//����޸�json�ļ�����

//----��Ӧ���޸ĳ�ʲô----
//����� http://d.cqp.me/Pro/����/������Ϣ
#define CQAPPID "com.example.demo"

#define CQAPPINFO CQAPIVERTEXT "," CQAPPID

//����Ҫ��һ�仰
MUST_AppInfo_RETURN(CQAPPID)
















//--------Ӧ����ʽ��ʼ--------

//�����static,��ʾ���loggerֻ�б�cpp��Ч
static Logger logger("��Q����Ӧ��");

EVE_Startup_EX(Startup)
{
	logger.Info("Startup");
}
EVE_Enable_EX(Enable)
{
	logger.Info("Enable");
}

EVE_Disable_EX(Disable)
{
	logger.Info("Disable");
}

EVE_Exit_EX(Exit)
{
	logger.Info("Exit");
}

