






//��Ӧ���ȿ�appinfo






#include <CQSDK.h>
#include "appinfo.h"
//--------Ӧ����ʽ��ʼ--------
//��cpp��������ڲ��������ֹͣʱִ�б�Ҫ�ĳ�ʼ������β����



MUST_AppInfo_RETURN(CQAPIVERTEXT "," APP_ID)



//�����static,��ʾ���loggerֻ�б�cpp��Ч
static Logger logger("��Q����Ӧ��");





//ʹ��EVE_��ͷ�ĺ�ָ��
//���Կ�������һ������Ҫ����¼�����
//ʹ������������������Ҫ�����ĸ�ʽ
//���ɿ��ٿ�ʼʹ��
EVE_Startup_EX(Startup)
//name:��Q����
//priority:30000
//����2��Ϊע��,����json�Զ�����
//nameΪ�¼�����,һ���ʶ��;,����Ҫ�����¼�����
//priorityΪ�¼����ȼ�(�μ� cq.im/deveventpriority)
//��ͷ����Ϊ<//name:>��<//priority:>,�����пո��
//���û��name,Ĭ��Ϊ�¼���
//���û��priority,Ĭ��Ϊ30000
{
	logger.Info("Startup");
	//��������ִ���������ֻ��ִ��һ��
	//�������������ȫ����Դ
}






EVE_Enable_EX(Enable)
//name:���ý��޷���������
//priority:30000
{
	logger.Info("Enable");
	//Ӧ���п��ܶ������
	//����������������������ڲ���Ҫ����Դ
}






EVE_Disable_EX(Disable)
//name:���ý����ܱ�������
//priority:30000
{
	logger.Info("Disable");
	//Ӧ���п��ܶ��ֹͣ
	//����ֹͣ��dll�����Լ�������
	//�����ղ����κ��¼�Ҳ���������κ�API
}






EVE_Exit_EX(Exit)
//name:�˳�����
//priority:30000
{
	logger.Info("Exit");
	//������ִ���Ժ�,��Q���ʱ���ڽ�������
}






//��������ת�� Msg.cpp �Լ���