#include onec
#pragma comment(lib,"CQ_SDK.lib")
//--------��ʼ֮ǰ--------

//���Ҽ�<CQ_APP>��Ŀ,ѡ��<����>,���޸���������:
//	Windows SDK
//	ƽ̨���߼�
//����Ҫ����Ϊ����װ�İ汾
//<CQ_SDK>��Ŀͬ��

//Ȼ���޸��Ϸ�x64Ϊx86,��Q�����֧��64λ

//����볢�Ա������Ŀ,���ų����ܵı���

//�������
//�벻Ҫ����debug��
//���������Ӧ�����������������������ٷ���(�����ҵĵ����Ϻúõ�ѽ?)



//--------Ӧ����Ϣ--------

#define APP_ID "com.example.demo"
//----����ʲô----
//�������Ĳ������,һ����һ�޶�������
//----��Ӧ�ð���ʲôԭ������----
//����� http://d.cqp.me/Pro/����/������Ϣ


#define CQAPPINFO CQAPIVERTEXT "," APP_ID
MUST_AppInfo_RETURN(APP_ID)


//����������ҪCQJSONС����֧��
//��Ҫ��<���ɺ��¼�>��<������>д����������
/*

*/

// Ӧ������
#define APP_anem "��Q����Ӧ��"

// Ӧ�ð汾
#define APP_version "1.0.0(alpha)"

// Ӧ��˳��汾��ÿ�η���ʱС�����Զ�����+1��
#define APP_version_id 0

// Ӧ������
#define APP_author "Example"

//һ�仰���������;
#define APP_description "��Q����Ӧ��(V9Ӧ�û���)"

//Ȩ��ȷ��,��ֻ�����ؼ�Ȩ��.
//#define APP_auth_20 "ȡCookies"//[����]
//#define APP_auth_30 "��������"
#define APP_auth_101 "����Ⱥ��Ϣ"
#define APP_auth_103 "������������Ϣ"
#define APP_auth_106 "����˽����Ϣ"
//#define APP_auth_110 "������"//[����]
#define APP_auth_120 "��ȺԱ�Ƴ�"
#define APP_auth_121 "��ȺԱ����"
#define APP_auth_122 "��Ⱥ����Ա"
#define APP_auth_123 "��ȫȺ����"
#define APP_auth_124 "������ȺԱ����"
#define APP_auth_125 "��Ⱥ��������"
#define APP_auth_126 "��Ⱥ��Ա��Ƭ"
//#define APP_auth_127 "��Ⱥ�˳�"//[����]
#define APP_auth_128 "��Ⱥ��Աר��ͷ��"
#define APP_auth_130 "ȡȺ��Ա��Ϣ"
#define APP_auth_131 "ȡİ������Ϣ"
#define APP_auth_140 "���������˳�"
#define APP_auth_150 "�ú����������"
#define APP_auth_151 "��Ⱥ�������"
#define APP_auth_160 "ȡȺ��Ա�б�"
#define APP_auth_161 "ȡȺ�б�"
#define APP_auth_180 "������Ϣ"

//��QĿ¼,ֱ�����ɵ���QĿ¼
#define CQ_DIR "D:\\CQP\\"


//��������ת�� appmain.cpp �Լ���