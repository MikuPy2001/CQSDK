#ifdef _DEBUG
#pragma comment(lib,"CQ_SDK_DEBUG.lib")
#else
#pragma comment(lib,"CQ_SDK.lib")
#endif // _DEBUG
#include <CQSDK.h>
//--------��ʼ֮ǰ--------

//���Ҽ�<CQ_APP>��Ŀ,ѡ��<����>,���޸���������:
//	Windows SDK 10.0
//	ƽ̨���߼� v142
//����Ҫ����Ϊ����װ�İ汾
//<CQ_SDK>��Ŀͬ��
//���ѡ��v142,����Ҫ�û���װ VC++ runtime 2015 x86

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
//����� https://docs.cqp.im/dev/v9/appid/




//����������ҪCQJSONС����֧��
//�������ʹ��,����Ҫ�ֶ���дJSON
//�������ʹ��,��ֱ��ת�� appmain.cpp �Լ���

//���ʹ��CQJSONС����
//��Ҫ��<��Ŀ����>��<���ɺ��¼�>��<������>д����������
//Ĭ���Ѿ�д��
/*
$(SolutionDir)CQ_Json.exe $(ProjectDir) $(TargetDir)
*/

// Ӧ������
#define APP_name "��Q����Ӧ��"

// Ӧ�ð汾
#include "appVer.h"

// Ӧ������
#define APP_author "Example"

//һ�仰���������;
#define APP_description "��Q����Ӧ��(V9Ӧ�û���)" //ע�Ͳ�Ӱ�����Ч��
#define ��дʾ�� "ʾ��""""\n�ڶ���,"
//              ��    ��           ��
//              ��ʼ�յ�һ�����ſ�ʼ,�����Ƿ�����ʵ����
//                    ���м�����ȫ������,��VS����������ͬ
//                                 ��ֱ��ƥ�����һ��������Ϊ����

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
#define APP_auth_132 "ȡȺ��Ϣ"
#define APP_auth_131 "ȡİ������Ϣ"
#define APP_auth_140 "���������˳�"
#define APP_auth_150 "�ú����������"
#define APP_auth_151 "��Ⱥ�������"
#define APP_auth_160 "ȡȺ��Ա�б�"
#define APP_auth_161 "ȡȺ�б�"
#define APP_auth_162 "ȡ�����б�"
#define APP_auth_180 "������Ϣ"

//��QĿ¼,ֱ�����ɵ���QĿ¼
#define CQ_DIR "C:\\CQDIR\\"




//��������ת�� appmain.cpp �Լ���
           