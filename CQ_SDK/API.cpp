#include "API.h"
#include "toolWin.h"

#include "BaseAPI.h"
#include "AuthCode.h"
#include "tool.h"

#include <string>

using namespace std;

int lasterr;
string CQtoString(�ı��� data, string API����);

//����������־
//���ȼ�ΪLOG_��ͷ�ĳ���
������ CQ::addLog(������ LOG_, �ı��� ����, �ı��� ����) { return lasterr = CQ_addLog(getAuthCode(), LOG_, ����, ����); }

//���ͺ�����Ϣ
������ CQ::sendPrivateMsg(�������� Account, �ı��� msg) { return  CQ_sendPrivateMsg(getAuthCode(), Account, msg); }

//���ͺ�����Ϣ
������ CQ::sendPrivateMsg(�������� Account, std::string & msg) { return sendPrivateMsg(Account, msg.c_str()); }

//���ͺ�����Ϣ
//������ CQ::sendPrivateMsg(EVEPrivateMsg eve, std::string msg) { return sendPrivateMsg(eve.fromAccount, msg.c_str()); }

//����Ⱥ��Ϣ
������ CQ::sendGroupMsg(�������� Ⱥ��, �ı��� msg) { return  CQ_sendGroupMsg(getAuthCode(), Ⱥ��, msg); }

//����Ⱥ��Ϣ
������ CQ::sendGroupMsg(�������� Ⱥ��, std::string & msg) { return sendGroupMsg(Ⱥ��, msg.c_str()); }

������ CQ::sendDiscussMsg(�������� �������, �ı��� msg) { return   CQ_sendDiscussMsg(getAuthCode(), �������, msg); }

//������������Ϣ
������ CQ::sendDiscussMsg(�������� �������, std::string & msg) { return sendDiscussMsg(�������, msg.c_str()); }

//������
������ CQ::sendLike(�������� AccountID, ������ times) { return lasterr = CQ_sendLikeV2(getAuthCode(), AccountID, times); }

//ȡCookies (���ã��˽ӿ���Ҫ�ϸ���Ȩ)
string CQ::getCookies(string domain) { return CQtoString(CQ_getCookiesV2(getAuthCode(), domain.c_str	()), "ȡCookies"); }

//��������
�ı��� CQ::getRecord(�ı��� file, �ı��� outformat) { return CQ_getRecordV2(getAuthCode(), file, outformat); }

//��������
std::string CQ::getRecord(std::string & file, std::string outformat) { return CQtoString(getRecord(file.c_str(), outformat.c_str()), "��������"); }

//ȡCsrfToken (���ã��˽ӿ���Ҫ�ϸ���Ȩ)
������ CQ::getCsrfToken() { return  CQ_getCsrfToken(getAuthCode()); }

//ȡӦ��Ŀ¼
string CQ::getAppDirectory() { return CQtoString(CQ_getAppDirectory(getAuthCode()), "ȡӦ��Ŀ¼"); }

//ȡ��¼Account
�������� CQ::getLoginAccount() { return  CQ_getLoginAccount(getAuthCode()); }

//ȡ��¼�ǳ�
string CQ::getLoginNick() { return CQtoString(CQ_getLoginNick(getAuthCode()), "ȡ��¼�ǳ�"); }

//��ȺԱ�Ƴ�
������ CQ::setGroupKick(�������� Ⱥ��, �������� AccountID, �߼��� �ܾ��ټ�Ⱥ) { return lasterr = CQ_setGroupKick(getAuthCode(), Ⱥ��, AccountID, �ܾ��ټ�Ⱥ); }

//��ȺԱ����
������ CQ::setGroupBan(�������� Ⱥ��, �������� AccountID, �������� ����ʱ��) { return lasterr = CQ_setGroupBan(getAuthCode(), Ⱥ��, AccountID, ����ʱ��); }

//��Ⱥ����Ա
������ CQ::setGroupAdmin(�������� Ⱥ��, �������� AccountID, �߼��� ��Ϊ����Ա) { return lasterr = CQ_setGroupAdmin(getAuthCode(), Ⱥ��, AccountID, ��Ϊ����Ա); }

//��Ⱥ��Աר��ͷ��
������ CQ::setGroupSpecialTitle(�������� Ⱥ��, �������� AccountID, �ı��� ͷ��, �������� ����ʱ��) { return lasterr = CQ_setGroupSpecialTitle(getAuthCode(), Ⱥ��, AccountID, ͷ��, ����ʱ��); }

//��Ⱥ��Աר��ͷ��
������ CQ::setGroupSpecialTitle(�������� Ⱥ��, �������� AccountID, std::string & ͷ��, �������� ����ʱ��) { return setGroupSpecialTitle(Ⱥ��, AccountID, ͷ��.c_str(), ����ʱ��); }

//��ȫȺ����
������ CQ::setGroupWholeBan(�������� Ⱥ��, �߼��� ��������) { return lasterr = CQ_setGroupWholeBan(getAuthCode(), Ⱥ��, ��������); }

//������ȺԱ����
������ CQ::setGroupAnonymousBan(�������� Ⱥ��, �ı��� ����, �������� ����ʱ��) { return lasterr = CQ_setGroupAnonymousBan(getAuthCode(), Ⱥ��, ����, ����ʱ��); }

//��Ⱥ��������
������ CQ::setGroupAnonymous(�������� Ⱥ��, �߼��� ��������) { return lasterr = CQ_setGroupAnonymous(getAuthCode(), Ⱥ��, ��������); }

//��Ⱥ��Ա��Ƭ
������ CQ::setGroupCard(�������� Ⱥ��, �������� AccountID, �ı��� ����Ƭ_�ǳ�) { return lasterr = CQ_setGroupCard(getAuthCode(), Ⱥ��, AccountID, ����Ƭ_�ǳ�); }

//��Ⱥ��Ա��Ƭ
������ CQ::setGroupCard(�������� Ⱥ��, �������� AccountID, std::string ����Ƭ_�ǳ�) { return setGroupCard(Ⱥ��, AccountID, ����Ƭ_�ǳ�.c_str()); }

//��Ⱥ�˳�
������ CQ::setGroupLeave(�������� Ⱥ��, �߼��� �Ƿ��ɢ) { return lasterr = CQ_setGroupLeave(getAuthCode(), Ⱥ��, �Ƿ��ɢ); }

//���������˳�
������ CQ::setDiscussLeave(�������� �������) { return lasterr = CQ_setDiscussLeave(getAuthCode(), �������); }

//�ú����������
������ CQ::setFriendAddRequest(�ı��� ��������ʶ, ������ ��������, �ı��� ��ע) { return lasterr = CQ_setFriendAddRequest(getAuthCode(), ��������ʶ, ��������, ��ע); }

//��Ⱥ�������
������ CQ::setGroupAddRequest(�ı��� ��������ʶ, ������ ��������, ������ ��������, �ı��� ����) { return lasterr = CQ_setGroupAddRequestV2(getAuthCode(), ��������ʶ, ��������, ��������, ����); }

//������������ʾ
������ CQ::setFatal(�ı��� ������Ϣ) { return lasterr = CQ_setFatal(getAuthCode(), ������Ϣ); }

//ȡȺ��Ա��Ϣ (֧�ֻ���)
GroupMemberInfo CQ::getGroupMemberInfo(�������� Ⱥ��, �������� AccountID, �߼��� ��ʹ�û���) { return GroupMemberInfo(CQtoString(CQ_getGroupMemberInfoV2(getAuthCode(), Ⱥ��, AccountID, ��ʹ�û���), "ȡȺ��Ա��Ϣ")); }

//ȡİ������Ϣ (֧�ֻ���)
StrangerInfo CQ::getStrangerInfo(�������� AccountID, �߼��� ��ʹ�û���) { return StrangerInfo(CQtoString(CQ_getStrangerInfo(getAuthCode(), AccountID, ��ʹ�û���), "ȡİ������Ϣ")); }

//ȡȺ��Ա�б�
std::vector<GroupMemberInfo> CQ::getGroupMemberList(�������� Ⱥ��) {
	auto data = CQtoString(CQ_getGroupMemberList(getAuthCode(), Ⱥ��), "ȡȺ��Ա�б�");
	if (data.empty()) {
		string log = string("API(ȡȺ��Ա�б�)���ؿ�����,Ⱥ��:") + to_string(Ⱥ��);
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
		string log = "ȡȺ��Ա�б������쳣, Ⱥ��:" + to_string(Ⱥ��) + " ����:" + to_string(len) + ",ʵ��:" + to_string(len1);
		addLog(Log_Debug, "CQSDK(CPP)", log.c_str());
	}

	return infovector;
}

//ȡȺ�б�
std::map<long long, std::string> CQ::getGroupList() {
	auto source = CQtoString(CQ_getGroupList(getAuthCode()), "ȡȺ�б�"); // ��ȡԭʼ����
	if (source.empty()) {
		string log = string("API(ȡȺ�б�)���ؿ�����");
		addLog(Log_Debug, "CQSDK(CPP)", log.c_str());
		return map<long long, std::string>();
	}

	string data(base64_decode(source)); // ����
	Unpack pack(data);// ת��ΪUnpack

	int len = pack.getInt();//��ȡ��Ⱥ��
	int len1 = 0;
	std::map<long long, std::string> ret;
	while (pack.len() > 0) {//�������ʣ������,�ͼ�����ȡ
		auto tep = pack.getUnpack();//��ȡ��һ��Ⱥ
		long long ID = tep.getLong();//��ȡȺ��
		string name = tep.getstring();//��ȡȺ����
		ret[ID] = name;//д��map
		len1++;
	}
	if (len1 != len) {
		string log = "API(ȡȺ�б�)�����쳣, ����:" + to_string(len) + ",ʵ��:" + to_string(len1);
		addLog(Log_Debug, "CQSDK(CPP)", log.c_str());
	}

	return ret;
}

������ CQ::deleteMsg(�������� MsgId)
{
	return lasterr = CQ_deleteMsg(getAuthCode(), MsgId);
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
	return CQtoString(CQ_getImage(getAuthCode(), file.c_str()), "����ͼƬ");
}

// 9.25
std::vector<FriendInfo> CQ::getFriendList()
{
	//����_ת��_�ı��������б���Ϣa
	auto data = CQtoString(CQ_getFriendList(getAuthCode(),false), "ȡ�����б�");
	if (data.empty()) {
		string log = string("API(ȡ�����б�)���ؿ�����");
		addLog(Log_Debug, "CQSDK(CPP)", log.c_str());
		return vector<FriendInfo>();
	}

	vector<FriendInfo> infovector;

	Unpack u(base64_decode(data));
	auto len = u.getInt();
	int len1 = 0;
	while (u.len() > 0)
	{
		//����_ת��_ansihex��������Ϣ
		infovector.emplace_back(u.getUnpack());
		len1++;
	}
	if (len1 != len) {
		string log = "API(ȡ�����б�)�����쳣, ����:" + to_string(len) + ",ʵ��:" + to_string(len1);
		addLog(Log_Debug, "CQSDK(CPP)", log.c_str());
	}

	return infovector;
}

GroupInfo CQ::getGroupInfo(�������� Ⱥ��, �߼��� ��ʹ�û���)
{
	//����_ת��_�ı���Ⱥ��Ϣ
	auto data = CQtoString(CQ_getGroupInfo(getAuthCode(), Ⱥ��, ��ʹ�û���), "ȡȺ��Ϣ");
	if (data.empty()) {
		string log = string("API(ȡȺ��Ϣ)���ؿ�����");
		addLog(Log_Debug, "CQSDK(CPP)", log.c_str());
		return GroupInfo();
	}
	Unpack u(base64_decode(data));

	GroupInfo Ⱥ��Ϣ;

	Ⱥ��Ϣ.Ⱥ�� = u.getLong();
	Ⱥ��Ϣ.���� = u.getstring();
	Ⱥ��Ϣ.��ǰ���� = u.getInt();
	Ⱥ��Ϣ.�������� = u.getInt();

	return Ⱥ��Ϣ;
}

//��������Ҫ�ĺ���
string CQtoString(�ı��� data, string API����) {
	if (CQStringCanRead(data)) {
		return data;
	}
	string log = API���� + "ʱ�����쳣,API����ָ��Ϊ����: " + to_string((int)data);
	addLog(Log_Debug, "CQSDK(CPP)", log.c_str());
	return "";
}

const char * CQ::getlasterrmsg()
{
	switch (lasterr)
	{
	case 0:    return "�����ɹ�"; case -1:   return "������ʧ��"; case -2:   return "δ�յ��������ظ�������δ���ͳɹ�"; case -3:   return "��Ϣ������Ϊ��"; case -4:   return "��Ϣ���������쳣"; case -5:   return "��־����δ����"; case -6:   return "��־���ȼ�����"; case -7:   return "�������ʧ��"; case -8:   return "��֧�ֶ�ϵͳ�ʺŲ���"; case -9:   return "�ʺŲ��ڸ�Ⱥ�ڣ���Ϣ�޷�����"; case -10:  return "���û�������/����Ⱥ��"; case -11:  return "���ݴ����޷�������"; case -12:  return "��֧�ֶ�������Ա�������"; case -13:  return "�޷�����Ҫ���Ե�������Ա����"; case -14:  return "����δ֪ԭ�򣬲���ʧ��"; case -15:  return "Ⱥδ�����������Թ��ܣ��������ʺű�����"; case -16:  return "�ʺŲ���Ⱥ�ڻ���������޷��˳�/��ɢ��Ⱥ"; case -17:  return "�ʺ�ΪȺ�����޷��˳���Ⱥ"; case -18:  return "�ʺŷ�Ⱥ�����޷���ɢ��Ⱥ"; case -19:  return "��ʱ��Ϣ��ʧЧ��δ����"; case -20:  return "��������"; case -21:  return "��ʱ��Ϣ��ʧЧ��δ����"; case -22:  return "��ȡAccount��Ϣʧ��"; case -23:  return "�Ҳ�����Ŀ��Account�Ĺ�ϵ����Ϣ�޷�����"; case -99:  return "�����õĹ����޷��ڴ˰汾��ʵ��"; case -101: return "Ӧ�ù���"; case -102: return "���ǺϷ���Ӧ��"; case -103: return "���ǺϷ���Ӧ��"; case -104: return "Ӧ�ò����ڹ�����Information����"; case -105: return "�޷�����Ӧ����Ϣ"; case -106: return "�ļ�����Ӧ��ID��ͬ"; case -107: return "������Ϣ��������"; case -108: return "AppInfo���ص�Api�汾��֧��ֱ�Ӽ��أ���֧��Api�汾Ϊ9(������)��Ӧ��ֱ�Ӽ���"; case -109: return "AppInfo���ص�AppID����"; case -110: return "ȱʧAppInfo���ص�AppID��Ӧ��[Appid].json�ļ�"; case -111: return "[Appid].json�ļ��ڵ�AppID�����ļ�����ͬ"; case -120: return "��Api��Ȩ���պ���(Initialize)"; case -121: return "Api��Ȩ���պ���(Initialize)����ֵ��0"; case -122: return "���Զ����޸Ŀ�Q�����ļ�����ȡ�����ز��رտ�Q"; case -150: return "�޷�����Ӧ����Ϣ"; case -151: return "Ӧ����ϢJson������ʧ�ܣ�����Json���Ƿ���ȷ"; case -152: return "Api�汾���ɻ����"; case -153: return "Ӧ����Ϣ��������ȱʧ"; case -154: return "Appid���Ϸ�"; case -160: return "�¼�����(Type)�����ȱʧ"; case -161: return "�¼�����(Function)�����ȱʧ"; case -162: return "Ӧ�����ȼ���Ϊ10000��20000��30000��40000�е�һ��"; case -163: return "�¼�����(Api)��֧��Ӧ��Api�汾"; case -164: return "Ӧ��Api�汾����8����ʹ�����°汾��ͣ�õ��¼�����(Type)��1(������Ϣ)��3(��ʱ��Ϣ)"; case -165: return "�¼�����Ϊ2(Ⱥ��Ϣ)��4(��������Ϣ)��21(˽����Ϣ)����ȱ��������ʽ(regex)�ı��ʽ����(expression)"; case -166: return "����Ϊ�յ�������ʽ(regex)��key"; case -167: return "����Ϊ�յ�������ʽ(regex)�ı��ʽ����(expression)"; case -168: return "Ӧ���¼�(event)id���������ڻ�Ϊ0"; case -169: return "Ӧ���¼�(event)id�������ظ�"; case -180: return "Ӧ��״̬(status)id���������ڻ�Ϊ0"; case -181: return "Ӧ��״̬(status)period���������ڻ����ô���"; case -182: return "Ӧ��״̬(status)id�������ظ�"; case -201: return "�޷�����Ӧ�ã�������Ӧ���ļ�����"; case -202: return "Api�汾���ɻ����"; case -997: return "Ӧ��δ����"; case -998: return "Ӧ�õ�����Auth����֮��� ��Q Api��";      	default:   return "δ֪����,���� ����Py2001 ����������SDK";
	}
}
