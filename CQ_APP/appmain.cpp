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

//�����static,��ʾ���loggerֻ�б�cpp��Ч
static Logger logger("��Q����Ӧ��");

EVE_Startup(Startup) 
{
	logger.Info("Startup");
	return 0;
}
EVE_Enable(Enable)
{
	logger.Info("Enable");
	return 0;
}

EVE_Disable(Disable)
{
	logger.Info("Disable");
	return 0;
}

EVE_Exit(Exit) 
{
	logger.Info("Exit");
	return 0;
}

