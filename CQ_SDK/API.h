#pragma once

#include "BaseAPI.h"
#include "StrangerInfo.h"
#include "GroupMemberInfo.h"

#include <string>
#include <map>
#include <vector>


inline
namespace CQ {
	//����������־
	������ addLog(������ ���ȼ�, �ı��� ����, �ı��� ����);

	//������������ʾ,��ʱ��֪����ʲô�õ�
	������ setFatal(�ı��� ������Ϣ);

	//���ͺ�����Ϣ
	//Auth=106 ʧ�ܷ��ظ�ֵ,�ɹ�������ϢID
	������ sendPrivateMsg(�������� Account, �ı��� msg);
	//���ͺ�����Ϣ
	//Auth=106 ʧ�ܷ��ظ�ֵ,�ɹ�������ϢID
	������ sendPrivateMsg(�������� Account, std::string&msg);

	//����Ⱥ��Ϣ
	//Auth=101 ʧ�ܷ��ظ�ֵ,�ɹ�������ϢID
	������ sendGroupMsg(�������� Ⱥ��, �ı��� msg);
	//����Ⱥ��Ϣ
	//Auth=101 ʧ�ܷ��ظ�ֵ,�ɹ�������ϢID
	������ sendGroupMsg(�������� Ⱥ��, std::string&msg);

	//������������Ϣ
	//Auth=103 ʧ�ܷ��ظ�ֵ,�ɹ�������ϢID
	������ sendDiscussMsg(�������� �������, �ı��� msg);
	//������������Ϣ
	//Auth=103 ʧ�ܷ��ظ�ֵ,�ɹ�������ϢID
	������ sendDiscussMsg(�������� �������, std::string&msg);

	//������ Auth=110
	������ sendLike(�������� AccountID, ������ times);

	//ȡCookies,Auth=20 ����,�˽ӿ���Ҫ�ϸ���Ȩ
	std::string getCookies();

	//��������
	//���Ƽ�ʹ��
	//ʹ����Ϻ�����CQFree()���ٷ���ֵ
	�ı��� getRecord(
		�ı��� file, // �յ���Ϣ�е������ļ��� (file)
		�ı��� outformat // Ӧ������ĸ�ʽ mp3,amr,wma,m4a,spx,ogg,wav,flac
	);
	//��������
	std::string getRecord(
		std::string&file, // �յ���Ϣ�е������ļ��� (file)
		std::string outformat // Ӧ������ĸ�ʽ mp3,amr,wma,m4a,spx,ogg,wav,flac
	);

	//ȡCsrfToken (���ã��˽ӿ���Ҫ�ϸ���Ȩ)
	//Auth=20 ��Account��ҳ�õ���bkn/g_tk�� ����,�˽ӿ���Ҫ�ϸ���Ȩ
	������ getCsrfToken();

	//ȡӦ��Ŀ¼,���ص�·��ĩβ��"\"
	std::string getAppDirectory();

	//ȡ��¼Account
	�������� getLoginAccount();

	//ȡ��¼�ǳ�
	std::string getLoginNick();

	//��ȺԱ�Ƴ� Auth=120
	������ setGroupKick(
		�������� Ⱥ��, �������� AccountID,
		�߼��� �ܾ��ټ�Ⱥ = false // ���Ϊ�棬�򡰲��ٽ��մ��˼�Ⱥ���롱��������
	);

	//��ȺԱ���� Auth=121
	������ setGroupBan(
		�������� Ⱥ��, �������� AccountID,
		�������� ����ʱ�� = 60 // ���Ե�ʱ�䣬��λΪ�롣���Ҫ�����������д0
	);

	//��Ⱥ����Ա Auth=122
	������ setGroupAdmin(
		�������� Ⱥ��, �������� AccountID,
		�߼��� ��Ϊ����Ա = true // ��/���ù���Ա ��/ȡ������Ա
	);

	//��Ⱥ��Աר��ͷ�� Auth=128 ��Ⱥ��Ȩ��
	������ setGroupSpecialTitle(
		�������� Ⱥ��, �������� AccountID,
		�ı��� ͷ��, // ���Ҫɾ�����������
		�������� = -1 // ר��ͷ����Ч�ڣ���λΪ�롣���������Ч��������д-1
	);
	//��Ⱥ��Աר��ͷ�� Auth=128 ��Ⱥ��Ȩ��
	������ setGroupSpecialTitle(
		�������� Ⱥ��, �������� AccountID,
		std::string&ͷ��, // ���Ҫɾ�����������
		�������� ����ʱ�� = -1 // ר��ͷ����Ч�ڣ���λΪ�롣���������Ч��������д-1
	);

	//��ȫȺ���� Auth=123
	������ setGroupWholeBan(
		�������� Ⱥ��,
		�߼��� �������� = true // ��/���� ��/�ر�
	);

	//������ȺԱ���� Auth=124
	������ setGroupAnonymousBan(
		�������� Ⱥ��,
		�ı��� ����, // Ⱥ��Ϣ�¼��յ��ġ�����������
		�������� ����ʱ�� = 60 // ���Ե�ʱ�䣬��λΪ�롣��֧�ֽ��
	);

	//��Ⱥ�������� Auth=125
	������ setGroupAnonymous(�������� Ⱥ��, �߼��� �������� = true);

	//��Ⱥ��Ա��Ƭ Auth=126
	������ setGroupCard(�������� Ⱥ��, �������� AccountID, �ı��� ����Ƭ_�ǳ�);

	//��Ⱥ��Ա��Ƭ Auth=126
	������ setGroupCard(�������� Ⱥ��, �������� AccountID, std::string ����Ƭ_�ǳ�);

	//��Ⱥ�˳� Auth=127 ����,�˽ӿ���Ҫ�ϸ���Ȩ
	������ setGroupLeave(
		�������� Ⱥ��,
		�߼��� �Ƿ��ɢ = false // ��/��ɢ��Ⱥ (Ⱥ��) ��/�˳���Ⱥ (����Ⱥ��Ա)
	);

	//���������˳� Auth=140
	������ setDiscussLeave(
		�������� �������
	);

	//�ú���������� Auth=150
	������ setFriendAddRequest(
		�ı��� ��������ʶ, // �����¼��յ��ġ�������ʶ������
		������ ��������, // #����_ͨ�� �� #����_�ܾ�
		�ı��� ��ע // ��Ӻ�ĺ��ѱ�ע
	);

	//��Ⱥ������� Auth=151
	������ setGroupAddRequest(
		�ı��� ��������ʶ, // �����¼��յ��ġ�������ʶ������
		������ ��������, // ���������¼������������� #����_Ⱥ��� �� #����_Ⱥ����
		������ ��������, // #����_ͨ�� �� #����_�ܾ�
		�ı��� ���� // �������ɣ��� #����_Ⱥ��� �� #����_�ܾ� ʱ����
	);

	//ȡȺ��Ա��Ϣ (֧�ֻ���) Auth=130
	GroupMemberInfo getGroupMemberInfo(�������� Ⱥ��, �������� AccountID, �߼��� ��ʹ�û��� = false);

	//ȡİ������Ϣ (֧�ֻ���) Auth=131
	StrangerInfo getStrangerInfo(�������� AccountID, �߼��� ��ʹ�û��� = false);

	//ȡȺ��Ա�б� Auth=160
	std::vector<GroupMemberInfo> getGroupMemberList(�������� Ⱥ��);

	//ȡȺ�б� Auth=161
	std::map<long long, std::string> getGroupList();

	//������Ϣ Auth=180
	������ deleteMsg(�������� MsgId);

	//�Ƿ�֧�ַ���ͼƬ�����ش��� 0 Ϊ֧�֣����� 0 Ϊ��֧��
	������ canSendImage();

	//�Ƿ�֧�ַ������������ش��� 0 Ϊ֧�֣����� 0 Ϊ��֧��
	������ canSendRecord();

	//����ͼƬ��������ͼƬ�ļ�����·��
	std::string getImage(std::string file);

	//���API���÷��ش������
	//�����ʹ�ñ�������ȡ���������Ϣ
	const char * getlasterrmsg();
}