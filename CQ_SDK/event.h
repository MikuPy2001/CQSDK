#pragma once

// ���ش�����Ϣ�����ٴ��ݸ�����Ӧ��
//ע�⣺Ӧ�����ȼ�����Ϊ���(10000)ʱ������ʹ�ñ�����ֵ
#define ��Ϣ_���� 1
// ������Ϣ�������ݸ�����Ӧ��
#define ��Ϣ_���� 0

#define ������_�� 1
#define ������_�� 2
#define ������_�� 3
#define ������_��� 4
#define ������_�� 5
#define ������_�� 6


/*
����Ӧ�õ�ApiVer��Appid������󽫲������
*/
#define MUST_AppInfo CQEVENT(const char*, AppInfo, 0)()

/*
����Ӧ�õ�ApiVer��Appid������󽫲������
*/
#define MUST_AppInfo_RETURN(CQAPPID) MUST_AppInfo{return CQAPIVERTEXT "," CQAPPID;}

/*
������ʧЧ,��ʹ�� getAuthCode(); ֱ�ӻ�ȡ, �˺�����CQAPI.h��

Ӧ��AuthCode����

�뱣�� AuthCode ,��ֵ�ǵ���CQAPI��ƾ֤

�벻Ҫ�ڱ����������������
*/
//#define MUST_Initialize CQEVENT(int, Initialize, 4)(int AuthCode)

///////////////////////////////// �¼� ������� /////////////////////////////////
//extern "C" __declspec(dllexport) void __stdcall Int32(int a){}//@4
//extern "C" __declspec(dllexport) void __stdcall Char(const char* a){}//@4
//extern "C" __declspec(dllexport) void __stdcall Int64(long long a){}//@8

/*
��Q����(Type=1001)

���ӳ�����ڿ�Q�����̡߳��б����á�
���۱�Ӧ���Ƿ����ã������������ڿ�Q������ִ��һ�Σ���������ִ�в����ʼ�����롣
����ؾ��췵�ر��ӳ��򣬷���Ῠס��������Լ�������ļ��ء�

�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���
��̶����� 0
*/
#define EVE_Startup(Name) CQEVENT(int, Name, 0)()
/*
��Q����(Type=1001)

���ӳ�����ڿ�Q�����̡߳��б����á�
���۱�Ӧ���Ƿ����ã������������ڿ�Q������ִ��һ�Σ���������ִ�в����ʼ�����롣
����ؾ��췵�ر��ӳ��򣬷���Ῠס��������Լ�������ļ��ء�

�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���
*/
#define EVE_Startup_EX(Name)\
void Name##_EX();\
EVE_Startup(Name){\
	Name##_EX();\
	return 0;\
}\
void Name##_EX()

/*
��Q�˳�(Type=1002)

���ӳ�����ڿ�Q�����̡߳��б����á�
���۱�Ӧ���Ƿ����ã������������ڿ�Q�˳�ǰִ��һ�Σ���������ִ�в���رմ��롣

�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���
��̶�����0�����غ��Q���ܿ�رգ��벻Ҫ��ͨ���̵߳ȷ�ʽִ���������롣
*/
#define EVE_Exit(Name) CQEVENT(int, Name, 0)()
/*
��Q�˳�(Type=1002)

���ӳ�����ڿ�Q�����̡߳��б����á�
���۱�Ӧ���Ƿ����ã������������ڿ�Q�˳�ǰִ��һ�Σ���������ִ�в���رմ��롣

�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���
��̶�����0�����غ��Q���ܿ�رգ��벻Ҫ��ͨ���̵߳ȷ�ʽִ���������롣
*/
#define EVE_Exit_EX(Name)\
void Name##_EX();\
EVE_Exit(Name){\
	Name##_EX();\
	return 0;\
}\
void Name##_EX()
/*
Ӧ���ѱ�����(Type=1003)

��Ӧ�ñ����ú󣬽��յ����¼���
�����Q����ʱӦ���ѱ����ã����� EVE_Startup(Type=1001,��Q����) �����ú󣬱�����Ҳ��������һ�Ρ�
��Ǳ�Ҫ����������������ش��ڡ���������Ӳ˵������û��ֶ��򿪴��ڣ�

�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���
��̶�����0��
*/
#define EVE_Enable(Name) CQEVENT(int, Name, 0)()
/*
Ӧ���ѱ�����(Type=1003)

��Ӧ�ñ����ú󣬽��յ����¼���
�����Q����ʱӦ���ѱ����ã����� EVE_Startup(Type=1001,��Q����) �����ú󣬱�����Ҳ��������һ�Ρ�
��Ǳ�Ҫ����������������ش��ڡ���������Ӳ˵������û��ֶ��򿪴��ڣ�

�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���
��̶�����0��
*/
#define EVE_Enable_EX(Name)\
void Name##_EX();\
EVE_Enable(Name){\
	Name##_EX();\
	return 0;\
}\
void Name##_EX()

/*
Ӧ�ý���ͣ��(Type=1004)

��Ӧ�ñ�ͣ��ǰ�����յ����¼���
�����Q����ʱӦ���ѱ�ͣ�ã��򱾺��������᡿�����á�
���۱�Ӧ���Ƿ����ã���Q�ر�ǰ�������������᡿�����á�

�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���
��̶�����0��
*/
#define EVE_Disable(Name) CQEVENT(int, Name, 0)()

/*
Ӧ�ý���ͣ��(Type=1004)

��Ӧ�ñ�ͣ��ǰ�����յ����¼���
�����Q����ʱӦ���ѱ�ͣ�ã��򱾺��������᡿�����á�
���۱�Ӧ���Ƿ����ã���Q�ر�ǰ�������������᡿�����á�

�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���
��̶�����0��
*/
#define EVE_Disable_EX(Name)\
void Name##_EX();\
EVE_Disable(Name){\
	Name##_EX();\
	return 0;\
}\
void Name##_EX()
/*
˽����Ϣ(Type=21)
���¼�ӵ��EX�汾,����ʹ��EX�汾

subType		�����ͣ�11/���Ժ��� 1/��������״̬ 2/����Ⱥ 3/����������
msgId		��ϢID
fromAccount		��ԴAccount
msg			��Ϣ����
font		����

���ӳ�����ڿ�Q���̡߳��б����ã���ע��ʹ�ö������Ҫ��ʼ��(CoInitialize,CoUninitialize)
�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���

����ֵ*����*ֱ�ӷ����ı�
���Ҫ�ظ���Ϣ�������api���ͣ����� ����(#��Ϣ_����) - �ضϱ�����Ϣ�����ټ������� //ע�⣺Ӧ�����ȼ�����Ϊ"���"(10000)ʱ������ʹ�ñ�����ֵ
������ظ���Ϣ������֮���Ӧ��/���������� ����(#��Ϣ_����) - ���Ա�����Ϣ
*/
#define EVE_PrivateMsg(Name) CQEVENT(int, Name, 24)(int subType, int msgId, long long fromAccount, const char* msg, int font)
/*
˽����Ϣ(Type=21)

subType		�����ͣ�11/���Ժ��� 1/��������״̬ 2/����Ⱥ 3/����������
msgId	��ϢID
fromAccount		��ԴAccount
msg			˽����Ϣ
font		����

���ӳ�����ڿ�Q���̡߳��б����ã���ע��ʹ�ö������Ҫ��ʼ��(CoInitialize,CoUninitialize)
�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���

����ֵ*����*ֱ�ӷ����ı�
���Ҫ�ظ���Ϣ�������api���ͣ����� ����(#��Ϣ_����) - �ضϱ�����Ϣ�����ټ������� //ע�⣺Ӧ�����ȼ�����Ϊ"���"(10000)ʱ������ʹ�ñ�����ֵ
������ظ���Ϣ������֮���Ӧ��/���������� ����(#��Ϣ_����) - ���Ա�����Ϣ
*/
#define EVE_PrivateMsg_EX(Name)																	\
	void Name(CQ::PrivateMsgEvent & e);															\
	EVE_PrivateMsg(Name)																		\
	{																							\
		CQ::PrivateMsgEvent tep(subType, msgId, fromAccount, msg, font);								\
		Name(tep);																				\
		return tep._EVEret;																		\
	}																							\
	void Name(CQ::PrivateMsgEvent & e)

/*
Ⱥ��Ϣ(Type=2)

subType		�����ͣ�Ŀǰ�̶�Ϊ1
msgId		��ϢID
fromGroup	��ԴȺ��
fromAccount		��ԴAccount��
fromAnonymous ��Դ������
msg			��Ϣ����
font		����

�����Ϣ����������,fromAccount �̶�Ϊ 80000000,��ʹ�ù��߽� fromAnonymous ת��Ϊ ��������Ϣ

���ӳ�����ڿ�Q���̡߳��б����ã���ע��ʹ�ö������Ҫ��ʼ��(CoInitialize,CoUninitialize)
�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���

����ֵ*����*ֱ�ӷ����ı�
���Ҫ�ظ���Ϣ�������api���ͣ����� ����(#��Ϣ_����) - �ضϱ�����Ϣ�����ټ������� //ע�⣺Ӧ�����ȼ�����Ϊ"���"(10000)ʱ������ʹ�ñ�����ֵ
������ظ���Ϣ������֮���Ӧ��/���������� ����(#��Ϣ_����) - ���Ա�����Ϣ
*/
#define EVE_GroupMsg(Name) CQEVENT(int, Name, 36)(int subType, int msgId, long long fromGroup, long long fromAccount, const char* fromAnonymous, const char* msg, int font)
/*
Ⱥ��Ϣ(Type=2)

subType �����ͣ�Ŀǰ�̶�Ϊ1
msgId ��ϢID
fromGroup ��ԴȺ��
fromAccount ��ԴAccount��
fromAnonymous ��Դ������
msg ��Ϣ����
font ����

�����Ϣ����������,isAnonymous() ���� true, ��ʹ�� getFromAnonymousInfo() ��ȡ ��������Ϣ

���ӳ�����ڿ�Q���̡߳��б����ã���ע��ʹ�ö������Ҫ��ʼ��(CoInitialize,CoUninitialize)
�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���

����ֵ*����*ֱ�ӷ����ı�
���Ҫ�ظ���Ϣ�������api���ͣ����� ����(#��Ϣ_����) - �ضϱ�����Ϣ�����ټ������� //ע�⣺Ӧ�����ȼ�����Ϊ"���"(10000)ʱ������ʹ�ñ�����ֵ
������ظ���Ϣ������֮���Ӧ��/���������� ����(#��Ϣ_����) - ���Ա�����Ϣ
*/
#define EVE_GroupMsg_EX(Name) 																	\
	void Name(CQ::GroupMsgEvent & e);															\
	EVE_GroupMsg(Name)																			\
	{																							\
		CQ::GroupMsgEvent tep(subType, msgId, fromGroup, fromAccount, fromAnonymous, msg, font);		\
		Name(tep);																				\
		return tep._EVEret;																		\
	}																							\
	void Name(CQ::GroupMsgEvent & e)

/*
��������Ϣ(Type=4)

subtype		�����ͣ�Ŀǰ�̶�Ϊ1
msgId		��ϢID
fromDiscuss	��Դ������
fromAccount		��ԴAccount��
msg			��Ϣ����
font		����

���ӳ�����ڿ�Q���̡߳��б����ã���ע��ʹ�ö������Ҫ��ʼ��(CoInitialize,CoUninitialize)
�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���

����ֵ*����*ֱ�ӷ����ı�
���Ҫ�ظ���Ϣ�������api���ͣ����� ����(#��Ϣ_����) - �ضϱ�����Ϣ�����ټ������� //ע�⣺Ӧ�����ȼ�����Ϊ"���"(10000)ʱ������ʹ�ñ�����ֵ
������ظ���Ϣ������֮���Ӧ��/���������� ����(#��Ϣ_����) - ���Ա�����Ϣ
*/
#define EVE_DiscussMsg(Name) CQEVENT(int, Name, 32)(int subType, int msgId, long long fromDiscuss, long long fromAccount, const char* msg, int font)
/*
��������Ϣ(Type=4)

subtype		�����ͣ�Ŀǰ�̶�Ϊ1
msgId		��ϢID
fromDiscuss	��Դ������
fromAccount		��ԴAccount��
msg			��Ϣ����
font		����

���ӳ�����ڿ�Q���̡߳��б����ã���ע��ʹ�ö������Ҫ��ʼ��(CoInitialize,CoUninitialize)
�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���

����ֵ*����*ֱ�ӷ����ı�
���Ҫ�ظ���Ϣ�������api���ͣ����� ����(#��Ϣ_����) - �ضϱ�����Ϣ�����ټ������� //ע�⣺Ӧ�����ȼ�����Ϊ"���"(10000)ʱ������ʹ�ñ�����ֵ
������ظ���Ϣ������֮���Ӧ��/���������� ����(#��Ϣ_����) - ���Ա�����Ϣ
*/
#define EVE_DiscussMsg_EX(Name)																	\
	void Name(CQ::DiscussMsgEvent & e);															\
	EVE_DiscussMsg(Name)																		\
	{																							\
		CQ::DiscussMsgEvent tep(subType, msgId, fromDiscuss, fromAccount, msg, font);					\
		Name(tep);																				\
		return tep._EVEret;																		\
	}																							\
	void Name(CQ::DiscussMsgEvent & e)

/*
Ⱥ�ļ��ϴ��¼�(Type=11)

subType �����ͣ�Ŀǰ�̶�Ϊ1
sendTime ����ʱ��(ʱ���)
fromGroup ��ԴȺ��
fromAccount ��ԴAccount��
file �ϴ��ļ���Ϣ,ʹ�� <����_ת��_�ı���Ⱥ�ļ�> ��������ת��Ϊ��Ч����,���༭

���ӳ�����ڿ�Q���̡߳��б����ã���ע��ʹ�ö������Ҫ��ʼ��(CoInitialize,CoUninitialize)
�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���

����ֵ*����*ֱ�ӷ����ı�
���Ҫ�ظ���Ϣ�������api���ͣ����� ����(#��Ϣ_����) - �ضϱ�����Ϣ�����ټ������� //ע�⣺Ӧ�����ȼ�����Ϊ"���"(10000)ʱ������ʹ�ñ�����ֵ
������ظ���Ϣ������֮���Ӧ��/���������� ����(#��Ϣ_����) - ���Ա�����Ϣ
*/
#define EVE_GroupUpload(Name) CQEVENT(int, Name, 28)(int subType, int sendTime, long long fromGroup,long long fromAccount, const char* file)

/*
Ⱥ�¼�-����Ա�䶯(Type=101)

subtype			�����ͣ�1/��ȡ������Ա 2/�����ù���Ա
sendTime ����ʱ��(ʱ���)
fromGroup		��ԴȺ��
beingOperateAccount	������Account

���ӳ�����ڿ�Q���̡߳��б����ã���ע��ʹ�ö������Ҫ��ʼ��(CoInitialize,CoUninitialize)
�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���

����ֵ*����*ֱ�ӷ����ı�
���Ҫ�ظ���Ϣ�������api���ͣ����� ����(#��Ϣ_����) - �ضϱ�����Ϣ�����ټ������� //ע�⣺Ӧ�����ȼ�����Ϊ"���"(10000)ʱ������ʹ�ñ�����ֵ
������ظ���Ϣ������֮���Ӧ��/���������� ����(#��Ϣ_����) - ���Ա�����Ϣ
*/
#define EVE_System_GroupAdmin(Name) CQEVENT(int, Name, 24)(int subType, int sendTime, long long fromGroup, long long beingOperateAccount)/*
/*
Ⱥ�¼�-����Ա�䶯(Type=101)

subtype			�����ͣ�1/��ȡ������Ա 2/�����ù���Ա
sendTime ����ʱ��(ʱ���)
fromGroup		��ԴȺ��
beingOperateAccount	������Account

���ӳ�����ڿ�Q���̡߳��б����ã���ע��ʹ�ö������Ҫ��ʼ��(CoInitialize,CoUninitialize)
�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���

����ֵ*����*ֱ�ӷ����ı�
���Ҫ�ظ���Ϣ�������api���ͣ����� ����(#��Ϣ_����) - �ضϱ�����Ϣ�����ټ������� //ע�⣺Ӧ�����ȼ�����Ϊ"���"(10000)ʱ������ʹ�ñ�����ֵ
������ظ���Ϣ������֮���Ӧ��/���������� ����(#��Ϣ_����) - ���Ա�����Ϣ
*/
#define EVE_System_GroupAdmin_EX(Name) \
	void Name(CQ::SystemGroupAdminEvent & e);\
	EVE_System_GroupAdmin(Name)\
	{\
		CQ::SystemGroupAdminEvent tep( subType, sendTime, fromGroup, beingOperateAccount);\
		Name(tep);\
		return tep._EVEret;																		\
	}\
	void Name(CQ::SystemGroupAdminEvent & e)

/*
Ⱥ�¼�-Ⱥ��Ա����(Type=102)

subtype		�����ͣ�1/ȺԱ�뿪 2/ȺԱ���� 3/�Լ�(����¼��)����
sendTime ����ʱ��(ʱ���)
fromGroup	��ԴȺ��
fromAccount		������Account(��������Ϊ2��3ʱ����)
beingOperateAccount ������Account

���ӳ�����ڿ�Q���̡߳��б����ã���ע��ʹ�ö������Ҫ��ʼ��(CoInitialize,CoUninitialize)
�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���

����ֵ*����*ֱ�ӷ����ı�
���Ҫ�ظ���Ϣ�������api���ͣ����� ����(#��Ϣ_����) - �ضϱ�����Ϣ�����ټ������� //ע�⣺Ӧ�����ȼ�����Ϊ"���"(10000)ʱ������ʹ�ñ�����ֵ
������ظ���Ϣ������֮���Ӧ��/���������� ����(#��Ϣ_����) - ���Ա�����Ϣ
*/
#define EVE_System_GroupMemberDecrease(Name) CQEVENT(int, Name, 32)(int subType, int sendTime, long long fromGroup, long long fromAccount, long long beingOperateAccount)

/*
Ⱥ�¼�-Ⱥ��Ա����(Type=103)

subtype �����ͣ�1/����Ա��ͬ�� 2/����Ա����
sendTime ����ʱ��(ʱ���)
fromGroup ��ԴȺ��
fromAccount ������Account(������ԱAccount)
beingOperateAccount ������Account(����Ⱥ��Account)

���ӳ�����ڿ�Q���̡߳��б����ã���ע��ʹ�ö������Ҫ��ʼ��(CoInitialize,CoUninitialize)
�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���

����ֵ*����*ֱ�ӷ����ı�
���Ҫ�ظ���Ϣ�������api���ͣ����� ����(#��Ϣ_����) - �ضϱ�����Ϣ�����ټ������� //ע�⣺Ӧ�����ȼ�����Ϊ"���"(10000)ʱ������ʹ�ñ�����ֵ
������ظ���Ϣ������֮���Ӧ��/���������� ����(#��Ϣ_����) - ���Ա�����Ϣ
*/
#define EVE_System_GroupMemberIncrease(Name) CQEVENT(int, Name, 32)(int subType, int sendTime, long long fromGroup, long long fromAccount, long long beingOperateAccount)

/*
�����¼�-���������(Type=201)

subtype �����ͣ�Ŀǰ�̶�Ϊ1
sendTime ����ʱ��(ʱ���)
fromAccount ��ԴAccount

���ӳ�����ڿ�Q���̡߳��б����ã���ע��ʹ�ö������Ҫ��ʼ��(CoInitialize,CoUninitialize)
�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���

����ֵ*����*ֱ�ӷ����ı�
���Ҫ�ظ���Ϣ�������api���ͣ����� ����(#��Ϣ_����) - �ضϱ�����Ϣ�����ټ������� //ע�⣺Ӧ�����ȼ�����Ϊ"���"(10000)ʱ������ʹ�ñ�����ֵ
������ظ���Ϣ������֮���Ӧ��/���������� ����(#��Ϣ_����) - ���Ա�����Ϣ
*/
#define EVE_Friend_Add(Name) CQEVENT(int, Name, 16)(int subType, int sendTime, long long fromAccount)
/*
�����¼�-���������(Type=201)

subtype �����ͣ�Ŀǰ�̶�Ϊ1
msgId ��ϢID
fromAccount ��ԴAccount

���ӳ�����ڿ�Q���̡߳��б����ã���ע��ʹ�ö������Ҫ��ʼ��(CoInitialize,CoUninitialize)
�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���

����ֵ*����*ֱ�ӷ����ı�
���Ҫ�ظ���Ϣ�������api���ͣ����� ����(#��Ϣ_����) - �ضϱ�����Ϣ�����ټ������� //ע�⣺Ӧ�����ȼ�����Ϊ"���"(10000)ʱ������ʹ�ñ�����ֵ
������ظ���Ϣ������֮���Ӧ��/���������� ����(#��Ϣ_����) - ���Ա�����Ϣ
*/
#define EVE_Friend_Add_EX(Name) \
	void Name(CQ::FriendAddEvent & e);\
	EVE_Friend_Add(Name)\
	{\
		CQ::FriendAddEvent tep(subType, sendTime, fromAccount);\
		Name(tep);\
		return tep._EVEret;																		\
	}\
	void Name(CQ::FriendAddEvent & e)

/*
����-�������(Type=301)

subtype �����ͣ�Ŀǰ�̶�Ϊ1
sendTime ����ʱ��(ʱ���)
fromAccount ��ԴAccount
msg ����
responseFlag ������ʶ(����������)

�ú���������� (responseFlag, #����_ͨ��)

���ӳ�����ڿ�Q���̡߳��б����ã���ע��ʹ�ö������Ҫ��ʼ��(CoInitialize,CoUninitialize)
�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���

����ֵ*����*ֱ�ӷ����ı�
���Ҫ�ظ���Ϣ�������api���ͣ����� ����(#��Ϣ_����) - �ضϱ�����Ϣ�����ټ������� //ע�⣺Ӧ�����ȼ�����Ϊ"���"(10000)ʱ������ʹ�ñ�����ֵ
������ظ���Ϣ������֮���Ӧ��/���������� ����(#��Ϣ_����) - ���Ա�����Ϣ
*/
#define EVE_Request_AddFriend(Name) CQEVENT(int, Name, 24)(int subType, int sendTime, long long fromAccount, const char* msg, const char* responseFlag)
/*
����-�������(Type=301)

subtype �����ͣ�Ŀǰ�̶�Ϊ1
sendTime ����ʱ��(ʱ���)
fromAccount ��ԴAccount
msg ����
responseFlag ������ʶ(����������)

�ú���������� (responseFlag, #����_ͨ��)

���ӳ�����ڿ�Q���̡߳��б����ã���ע��ʹ�ö������Ҫ��ʼ��(CoInitialize,CoUninitialize)
�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���

����ֵ*����*ֱ�ӷ����ı�
���Ҫ�ظ���Ϣ�������api���ͣ����� ����(#��Ϣ_����) - �ضϱ�����Ϣ�����ټ������� //ע�⣺Ӧ�����ȼ�����Ϊ"���"(10000)ʱ������ʹ�ñ�����ֵ
������ظ���Ϣ������֮���Ӧ��/���������� ����(#��Ϣ_����) - ���Ա�����Ϣ
*/
#define EVE_Request_AddFriend_EX(Name)															\
	void Name(CQ::RequestAddFriendEvent & e);													\
	EVE_Request_AddFriend(Name)																	\
	{																							\
		CQ::RequestAddFriendEvent tep(subType, sendTime, fromAccount, msg, responseFlag);	\
		Name(tep);																				\
		return tep._EVEret;																		\
	}																							\
	void Name(CQ::RequestAddFriendEvent & e)

/*
����-Ⱥ���(Type=302)

subtype �����ͣ�1/����������Ⱥ 2/�Լ�(����¼��)������Ⱥ
sendTime ����ʱ��(ʱ���)
fromGroup ��ԴȺ��
fromAccount ��ԴAccount
msg ����
responseFlag ������ʶ(����������)

��� subtype �� 1
��Ⱥ������� (responseFlag, #����_Ⱥ���, #����_ͨ��)
��� subtype �� 2
��Ⱥ������� (responseFlag, #����_Ⱥ����, #����_ͨ��)

���ӳ�����ڿ�Q���̡߳��б����ã���ע��ʹ�ö������Ҫ��ʼ��(CoInitialize,CoUninitialize)
�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���

����ֵ*����*ֱ�ӷ����ı�
���Ҫ�ظ���Ϣ�������api���ͣ����� ����(#��Ϣ_����) - �ضϱ�����Ϣ�����ټ������� //ע�⣺Ӧ�����ȼ�����Ϊ"���"(10000)ʱ������ʹ�ñ�����ֵ
������ظ���Ϣ������֮���Ӧ��/���������� ����(#��Ϣ_����) - ���Ա�����Ϣ
*/
#define EVE_Request_AddGroup(Name) CQEVENT(int, Name, 32)(int subType, int sendTime, long long fromGroup, long long fromAccount, const char* msg, const char* responseFlag)
/*
����-Ⱥ���(Type=302)

subtype �����ͣ�1/����������Ⱥ 2/�Լ�(����¼��)������Ⱥ
sendTime ����ʱ��(ʱ���)
fromGroup ��ԴȺ��
fromAccount ��ԴAccount
msg ����
responseFlag ������ʶ(����������)

��� subtype �� 1
��Ⱥ������� (responseFlag, #����_Ⱥ���, #����_ͨ��)
��� subtype �� 2
��Ⱥ������� (responseFlag, #����_Ⱥ����, #����_ͨ��)

���ӳ�����ڿ�Q���̡߳��б����ã���ע��ʹ�ö������Ҫ��ʼ��(CoInitialize,CoUninitialize)
�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���

����ֵ*����*ֱ�ӷ����ı�
���Ҫ�ظ���Ϣ�������api���ͣ����� ����(#��Ϣ_����) - �ضϱ�����Ϣ�����ټ������� //ע�⣺Ӧ�����ȼ�����Ϊ"���"(10000)ʱ������ʹ�ñ�����ֵ
������ظ���Ϣ������֮���Ӧ��/���������� ����(#��Ϣ_����) - ���Ա�����Ϣ
*/
#define EVE_Request_AddGroup_EX(Name) \
	void Name(CQ::RequestAddGroupEvent & e);\
	EVE_Request_AddGroup(Name)\
	{\
		CQ::RequestAddGroupEvent tep(subType, sendTime, fromGroup, fromAccount, msg, responseFlag);\
		Name(tep); 										\
		return tep._EVEret;\
	}\
	void Name(CQ::RequestAddGroupEvent & e)

/*
�˵�

���� .json �ļ������ò˵���Ŀ��������
�����ʹ�ò˵������� .json ���˴�ɾ�����ò˵�
�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���

����ֵ*����*ֱ�ӷ����ı�
���Ҫ�ظ���Ϣ�������api���ͣ����� ����(#��Ϣ_����) - �ضϱ�����Ϣ�����ټ������� //ע�⣺Ӧ�����ȼ�����Ϊ"���"(10000)ʱ������ʹ�ñ�����ֵ
������ظ���Ϣ������֮���Ӧ��/���������� ����(#��Ϣ_����) - ���Ա�����Ϣ
*/
#define EVE_Menu(Name) CQEVENT(int, Name, 0)()
/*
�˵�

���� .json �ļ������ò˵���Ŀ��������
�����ʹ�ò˵������� .json ���˴�ɾ�����ò˵�
�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���

����ֵ*����*ֱ�ӷ����ı�
���Ҫ�ظ���Ϣ�������api���ͣ����� ����(#��Ϣ_����) - �ضϱ�����Ϣ�����ټ������� //ע�⣺Ӧ�����ȼ�����Ϊ"���"(10000)ʱ������ʹ�ñ�����ֵ
������ظ���Ϣ������֮���Ӧ��/���������� ����(#��Ϣ_����) - ���Ա�����Ϣ
*/
#define EVE_Menu_EX(Name)\
void Name##_EX();\
EVE_Menu(Name){\
	Name##_EX();\
	return 0;\
}\
void Name##_EX()
/*
������

��ʹ��EX�汾
emmm,��ΪһЩԭ��,��������ʱ������...

���ӳ�����ڿ�Q���̡߳��б����ã���ע��ʹ�ö������Ҫ��ʼ��(CoInitialize,CoUninitialize)��
�������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���
*/
#define EVE_Status(Name) CQEVENT(const char*, Name, 0)()
/**
 * ������.
 * <p>
 * ������ e.data e.dataf e.color �����������ֲ�������
 * <p>
 * <p>
 * ���ӳ�����ڿ�Q���̡߳��б����ã���ע��ʹ�ö������Ҫ��ʼ��(CoInitialize,CoUninitialize).
 * <p>
 * �������ʹ���»��߿�ͷ��Ҫ�ĳ�˫�»���
 *
 * @param e
 */
#define EVE_Status_EX(Name)					\
	void Name(CQ::StatusEvent & e);\
	EVE_Status(Name)\
	{\
		CQ::StatusEvent tep;\
		static std::string ret;\
		Name(tep);										\
		ret = CQ::statusEVEreturn(tep);\
		return ret.c_str();\
	}\
	void Name(CQ::StatusEvent & e)
