/*
CoolQ SDK for VS2017
Api Version 9.13
Written by MukiPy2001 & Thanks for the help of orzFly and Coxxs
*/
#pragma once

#include "Base.h"

// ����       ��ɫ
#define Log_Debug 0
// ��Ϣ       ��ɫ
#define Log_Info 10
// ��Ϣ(�ɹ�) ��ɫ
#define Log_InfoSuccess 11
// ��Ϣ(����) ��ɫ
#define Log_InfoRecv 12
// ��Ϣ(����) ��ɫ
#define Log_InfoSend 13
// ����       ��ɫ
#define Log_Warning 20
// ����       ��ɫ
#define Log_Error 30
// ��������   ���
#define Log_Fatal 40

#define ����_ͨ�� 1
#define ����_�ܾ� 2

#define ����_Ⱥ��� 1
#define ����_Ⱥ���� 2
inline
namespace CQ {
	//����������־
	CQAPI(CQ_addLog, ������)(
		������ AuthCode,//
		������ ���ȼ�,// #Log_ ��ͷ����
		�ı��� ����,//
		�ı��� ����//
		);
	//���ͺ�����Ϣ
	//Auth=106 ʧ�ܷ��ظ�ֵ,�ɹ�������ϢID
	CQAPI(CQ_sendPrivateMsg, ������)(
		������ AuthCode,//
		�������� QQID,// Ŀ��QQ
		�ı��� msg// ��Ϣ����
		);
	//����Ⱥ��Ϣ
	//Auth=101 ʧ�ܷ��ظ�ֵ,�ɹ�������ϢID
	CQAPI(CQ_sendGroupMsg, ������)(
		������ AuthCode,//
		�������� Ⱥ��,// Ŀ��Ⱥ
		�ı��� msg// ��Ϣ����
		);
	//������������Ϣ
	//Auth=103 ʧ�ܷ��ظ�ֵ,�ɹ�������ϢID
	CQAPI(CQ_sendDiscussMsg, ������)(
		������ AuthCode,//
		�������� �������,// Ŀ��������
		�ı��� msg// ��Ϣ����
		);
	//������ Auth=110
	//CQAPI(CQ_sendLike, ������)(
	//	������ AuthCode,//
	//	�������� QQID// Ŀ��QQ
	//	);

	//������V2 Auth=110
	CQAPI(CQ_sendLikeV2, ������)(
		������ AuthCode,//
		�������� QQID,// Ŀ��QQ
		������ times// �޵Ĵ��������10��
		);
	//ȡCookies (���ã��˽ӿ���Ҫ�ϸ���Ȩ)
	//Auth=20 ����,�˽ӿ���Ҫ�ϸ���Ȩ
	CQAPI(CQ_getCookies, �ı���)(
		������ AuthCode//
		);
	//��������
	CQAPI(CQ_getRecord, �ı���)(
		������ AuthCode,//
		�ı��� file,// �յ���Ϣ�е������ļ��� (file)
		�ı��� outformat// Ӧ������ĸ�ʽ  mp3,amr,wma,m4a,spx,ogg,wav,flac
		);
	//ȡCsrfToken (���ã��˽ӿ���Ҫ�ϸ���Ȩ)
	//Auth=20 ��QQ��ҳ�õ���bkn/g_tk�� ����,�˽ӿ���Ҫ�ϸ���Ȩ
	CQAPI(CQ_getCsrfToken, ������)(
		������ AuthCode//
		);
	//ȡӦ��Ŀ¼
	//���ص�·��ĩβ��"\"
	CQAPI(CQ_getAppDirectory, �ı���)(
		������ AuthCode//
		);
	//ȡ��¼QQ
	CQAPI(CQ_getLoginQQ, ��������)(
		������ AuthCode//
		);
	//ȡ��¼�ǳ�
	CQAPI(CQ_getLoginNick, �ı���)(
		������ AuthCode//
		);
	//��ȺԱ�Ƴ� Auth=120
	CQAPI(CQ_setGroupKick, ������)(
		������ AuthCode,//
		�������� Ⱥ��,// Ŀ��Ⱥ
		�������� QQID,// Ŀ��QQ
		�߼��� �ܾ��ټ�Ⱥ// ���Ϊ�棬�򡰲��ٽ��մ��˼�Ⱥ���롱��������
		);
	//��ȺԱ���� Auth=121
	CQAPI(CQ_setGroupBan, ������)(
		������ AuthCode,//
		�������� Ⱥ��,// Ŀ��Ⱥ
		�������� QQID,// Ŀ��QQ
		�������� ����ʱ��// ���Ե�ʱ�䣬��λΪ�롣���Ҫ�����������д0
		);
	//��Ⱥ����Ա Auth=122
	CQAPI(CQ_setGroupAdmin, ������)(
		������ AuthCode,//
		�������� Ⱥ��,// Ŀ��Ⱥ
		�������� QQID,// �����õ�QQ
		�߼��� ��Ϊ����Ա// ��/���ù���Ա ��/ȡ������Ա
		);
	//��Ⱥ��Աר��ͷ�� Auth=128 ��Ⱥ��Ȩ��
	CQAPI(CQ_setGroupSpecialTitle, ������)(
		������ AuthCode,//
		�������� Ⱥ��,// Ŀ��Ⱥ
		�������� QQID,// Ŀ��QQ
		�ı��� ͷ��,// ���Ҫɾ�����������
		�������� ����ʱ��// ר��ͷ����Ч�ڣ���λΪ�롣���������Ч��������д-1
		);
	//��ȫȺ���� Auth=123
	CQAPI(CQ_setGroupWholeBan, ������)(
		������ AuthCode,//
		�������� Ⱥ��,// Ŀ��Ⱥ
		�߼��� ��������// ��/���� ��/�ر�
		);
	//������ȺԱ���� Auth=124
	CQAPI(CQ_setGroupAnonymousBan, ������)(
		������ AuthCode,//
		�������� Ⱥ��,// Ŀ��Ⱥ
		�ı��� ����,// Ⱥ��Ϣ�¼��յ��ġ�����������
		�������� ����ʱ��// ���Ե�ʱ�䣬��λΪ�롣��֧�ֽ��
		);
	//��Ⱥ�������� Auth=125
	CQAPI(CQ_setGroupAnonymous, ������)(
		������ AuthCode,//
		�������� Ⱥ��,//
		�߼��� ��������//
		);
	//��Ⱥ��Ա��Ƭ Auth=126
	CQAPI(CQ_setGroupCard, ������)(
		������ AuthCode,//
		�������� Ⱥ��,// Ŀ��Ⱥ
		�������� QQID,// �����õ�QQ
		�ı��� ����Ƭ_�ǳ�//
		);
	//��Ⱥ�˳� Auth=127 ����,�˽ӿ���Ҫ�ϸ���Ȩ
	CQAPI(CQ_setGroupLeave, ������)(
		������ AuthCode,//
		�������� Ⱥ��,// Ŀ��Ⱥ
		�߼��� �Ƿ��ɢ// ��/��ɢ��Ⱥ (Ⱥ��) ��/�˳���Ⱥ (����Ⱥ��Ա)
		);
	//���������˳� Auth=140
	CQAPI(CQ_setDiscussLeave, ������)(
		������ AuthCode,//
		�������� �������// Ŀ��������
		);
	//�ú���������� Auth=150
	CQAPI(CQ_setFriendAddRequest, ������)(
		������ AuthCode,//
		�ı��� ��������ʶ,// �����¼��յ��ġ�������ʶ������
		������ ��������,// #����_ͨ�� �� #����_�ܾ�
		�ı��� ��ע// ��Ӻ�ĺ��ѱ�ע
		);
	//��Ⱥ������� Auth=151
	//CQAPI(CQ_setGroupAddRequest, ������)(
	//	������ AuthCode,//
	//	�ı��� ��������ʶ,// �����¼��յ��ġ�������ʶ������
	//	������ ��������,// ���������¼������������� #����_Ⱥ��� �� #����_Ⱥ����
	//	������ ��������// #����_ͨ�� �� #����_�ܾ�
	//	);

	//��Ⱥ������� Auth=151
	CQAPI(CQ_setGroupAddRequestV2, ������)(
		������ AuthCode,//
		�ı��� ��������ʶ,// �����¼��յ��ġ�������ʶ������
		������ ��������,// ���������¼������������� #����_Ⱥ��� �� #����_Ⱥ����
		������ ��������,// #����_ͨ�� �� #����_�ܾ�
		�ı��� ����// �������ɣ��� #����_Ⱥ��� �� #����_�ܾ� ʱ����
		);
	//������������ʾ
	CQAPI(CQ_setFatal, ������)(
		������ AuthCode,//
		�ı��� ������Ϣ//
		);
	//ȡȺ��Ա��Ϣ (�ɰ�,����CQ_getGroupMemberInfoV2) Auth=130
	//CQAPI(CQ_getGroupMemberInfo, �ı���)(
	//	������ AuthCode,//
	//	�������� Ⱥ��,// Ŀ��QQ����Ⱥ
	//	�������� QQID// Ŀ��QQ
	//	);

	//ȡȺ��Ա��Ϣ (֧�ֻ���) Auth=130
	CQAPI(CQ_getGroupMemberInfoV2, �ı���)(
		������ AuthCode,//
		�������� Ⱥ��,// Ŀ��QQ����Ⱥ
		�������� QQID,// Ŀ��QQ
		�߼��� ��ʹ�û���
		);
	//ȡİ������Ϣ (֧�ֻ���) Auth=131
	CQAPI(CQ_getStrangerInfo, �ı���)(
		������ AuthCode,//
		�������� QQID,// Ŀ��QQ
		�߼��� ��ʹ�û���
		);
	//ȡȺ��Ա�б� Auth=160
	CQAPI(CQ_getGroupMemberList, �ı���)(
		������ AuthCode,//
		�������� Ⱥ��// Ŀ��QQ����Ⱥ
		);
	//ȡȺ�б� Auth=161
	CQAPI(CQ_getGroupList, �ı���)(
		������ AuthCode
		);
	//������Ϣ Auth=180
	CQAPI(CQ_deleteMsg, ������)(
		������ AuthCode,
		�������� MsgId
		);
}