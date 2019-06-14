#include "API.h"

#include "BaseAPI.h"
#include "AuthCode.h"
#include "tool.h"

using namespace std;

int lasterr;

//����������־
������ CQ::addLog(������ ���ȼ�, �ı��� ����, �ı��� ����) { return lasterr = CQ_addLog(getAuthCode(), ���ȼ�, ����, ����); }

//���ͺ�����Ϣ
������ CQ::sendPrivateMsg(�������� QQ, �ı��� msg) { return  CQ_sendPrivateMsg(getAuthCode(), QQ, msg); }

//���ͺ�����Ϣ
������ CQ::sendPrivateMsg(�������� QQ, std::string & msg) { return sendPrivateMsg(QQ, msg.c_str()); }

//���ͺ�����Ϣ
//������ CQ::sendPrivateMsg(EVEPrivateMsg eve, std::string msg) { return sendPrivateMsg(eve.fromQQ, msg.c_str()); }

//����Ⱥ��Ϣ
������ CQ::sendGroupMsg(�������� Ⱥ��, �ı��� msg) { return  CQ_sendGroupMsg(getAuthCode(), Ⱥ��, msg); }

//����Ⱥ��Ϣ
������ CQ::sendGroupMsg(�������� Ⱥ��, std::string & msg) { return sendGroupMsg(Ⱥ��, msg.c_str()); }

������ CQ::sendDiscussMsg(�������� �������, �ı��� msg) { return   CQ_sendDiscussMsg(getAuthCode(), �������, msg); }

//������������Ϣ
������ CQ::sendDiscussMsg(�������� �������, std::string & msg) { return sendDiscussMsg(�������, msg.c_str()); }

//������
������ CQ::sendLike(�������� QQID, ������ times) { return lasterr = CQ_sendLikeV2(getAuthCode(), QQID, times); }

//ȡCookies (���ã��˽ӿ���Ҫ�ϸ���Ȩ)
�ı��� CQ::getCookies() { return  CQ_getCookies(getAuthCode()); }

//��������
�ı��� CQ::getRecord(�ı��� file, �ı��� outformat) { return CQ_getRecord(getAuthCode(), file, outformat); }

//��������
std::string CQ::getRecord(std::string & file, std::string outformat) { return getRecord(file.c_str(), outformat.c_str()); }

//ȡCsrfToken (���ã��˽ӿ���Ҫ�ϸ���Ȩ)
������ CQ::getCsrfToken() { return  CQ_getCsrfToken(getAuthCode()); }

//ȡӦ��Ŀ¼
�ı��� CQ::getAppDirectory() { return  CQ_getAppDirectory(getAuthCode()); }

//ȡ��¼QQ
�������� CQ::getLoginQQ() { return  CQ_getLoginQQ(getAuthCode()); }

//ȡ��¼�ǳ�
�ı��� CQ::getLoginNick() { return  CQ_getLoginNick(getAuthCode()); }

//��ȺԱ�Ƴ�
������ CQ::setGroupKick(�������� Ⱥ��, �������� QQID, �߼��� �ܾ��ټ�Ⱥ) { return lasterr = CQ_setGroupKick(getAuthCode(), Ⱥ��, QQID, �ܾ��ټ�Ⱥ); }

//��ȺԱ����
������ CQ::setGroupBan(�������� Ⱥ��, �������� QQID, �������� ����ʱ��) { return lasterr = CQ_setGroupBan(getAuthCode(), Ⱥ��, QQID, ����ʱ��); }

//��Ⱥ����Ա
������ CQ::setGroupAdmin(�������� Ⱥ��, �������� QQID, �߼��� ��Ϊ����Ա) { return lasterr = CQ_setGroupAdmin(getAuthCode(), Ⱥ��, QQID, ��Ϊ����Ա); }

//��Ⱥ��Աר��ͷ��
������ CQ::setGroupSpecialTitle(�������� Ⱥ��, �������� QQID, �ı��� ͷ��, �������� ����ʱ��) { return lasterr = CQ_setGroupSpecialTitle(getAuthCode(), Ⱥ��, QQID, ͷ��, ����ʱ��); }

//��Ⱥ��Աר��ͷ��
������ CQ::setGroupSpecialTitle(�������� Ⱥ��, �������� QQID, std::string & ͷ��, �������� ����ʱ��) { return setGroupSpecialTitle(Ⱥ��, QQID, ͷ��.c_str(), ����ʱ��); }

//��ȫȺ����
������ CQ::setGroupWholeBan(�������� Ⱥ��, �߼��� ��������) { return lasterr = CQ_setGroupWholeBan(getAuthCode(), Ⱥ��, ��������); }

//������ȺԱ����
������ CQ::setGroupAnonymousBan(�������� Ⱥ��, �ı��� ����, �������� ����ʱ��) { return lasterr = CQ_setGroupAnonymousBan(getAuthCode(), Ⱥ��, ����, ����ʱ��); }

//��Ⱥ��������
������ CQ::setGroupAnonymous(�������� Ⱥ��, �߼��� ��������) { return lasterr = CQ_setGroupAnonymous(getAuthCode(), Ⱥ��, ��������); }

//��Ⱥ��Ա��Ƭ
������ CQ::setGroupCard(�������� Ⱥ��, �������� QQID, �ı��� ����Ƭ_�ǳ�) { return lasterr = CQ_setGroupCard(getAuthCode(), Ⱥ��, QQID, ����Ƭ_�ǳ�); }

//��Ⱥ��Ա��Ƭ
������ CQ::setGroupCard(�������� Ⱥ��, �������� QQID, std::string ����Ƭ_�ǳ�) { return setGroupCard(Ⱥ��, QQID, ����Ƭ_�ǳ�.c_str()); }

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
GroupMemberInfo CQ::getGroupMemberInfo(�������� Ⱥ��, �������� QQID, �߼��� ��ʹ�û���) { return GroupMemberInfo(CQ_getGroupMemberInfoV2(getAuthCode(), Ⱥ��, QQID, ��ʹ�û���)); }

//ȡİ������Ϣ (֧�ֻ���)
StrangerInfo CQ::getStrangerInfo(�������� QQID, �߼��� ��ʹ�û���) { return StrangerInfo(CQ_getStrangerInfo(getAuthCode(), QQID, ��ʹ�û���)); }

//ȡȺ��Ա�б�
std::vector<GroupMemberInfo> CQ::getGroupMemberList(�������� Ⱥ��) {
	�ı��� data = CQ_getGroupMemberList(getAuthCode(), Ⱥ��);
	vector<GroupMemberInfo> infovector;
	if (data==nullptr)  return infovector;
	if (data[0] == '\0')return infovector;

	Unpack u(base64_decode(data));
	auto i = u.getInt();
	while (i-- && u.len() > 0)
	{
		//infovector.push_back(GroupMemberInfo(u.getchars()));
		infovector.emplace_back(u.getUnpack());
	}

	return infovector;
}

//ȡȺ�б�
std::map<long long, std::string> CQ::getGroupList() {
	string source(CQ_getGroupList(getAuthCode()));// ��ȡԭʼ����
	string data(base64_decode(source)); // ����
	Unpack pack(data);// ת��ΪUnpack

	int len = pack.getInt();//��ȡ��Ⱥ��
	std::map<long long, std::string> ret;
	while (pack.len() > 0) {//�������ʣ������,�ͼ�����ȡ
		auto tep = pack.getUnpack();//��ȡ��һ��Ⱥ
		long long ID = tep.getLong();//��ȡȺ��
		string name = tep.getstring();//��ȡȺ����
		ret[ID] = name;//д��map
	}
	return ret;
}

������ CQ::deleteMsg(�������� MsgId)
{
	return lasterr = CQ_deleteMsg(getAuthCode(), MsgId);
}

const char * CQ::getlasterrmsg()
{
	switch (lasterr)
	{
	case 0:    return "�����ɹ�";
	case -1:   return "������ʧ��";
	case -2:   return "δ�յ��������ظ�������δ���ͳɹ�";
	case -3:   return "��Ϣ������Ϊ��";
	case -4:   return "��Ϣ���������쳣";
	case -5:   return "��־����δ����";
	case -6:   return "��־���ȼ�����";
	case -7:   return "�������ʧ��";
	case -8:   return "��֧�ֶ�ϵͳ�ʺŲ���";
	case -9:   return "�ʺŲ��ڸ�Ⱥ�ڣ���Ϣ�޷�����";
	case -10:  return "���û�������/����Ⱥ��";
	case -11:  return "���ݴ����޷�������";
	case -12:  return "��֧�ֶ�������Ա�������";
	case -13:  return "�޷�����Ҫ���Ե�������Ա����";
	case -14:  return "����δ֪ԭ�򣬲���ʧ��";
	case -15:  return "Ⱥδ�����������Թ��ܣ��������ʺű�����";
	case -16:  return "�ʺŲ���Ⱥ�ڻ���������޷��˳�/��ɢ��Ⱥ";
	case -17:  return "�ʺ�ΪȺ�����޷��˳���Ⱥ";
	case -18:  return "�ʺŷ�Ⱥ�����޷���ɢ��Ⱥ";
	case -19:  return "��ʱ��Ϣ��ʧЧ��δ����";
	case -20:  return "��������";
	case -21:  return "��ʱ��Ϣ��ʧЧ��δ����";
	case -22:  return "��ȡQQ��Ϣʧ��";
	case -23:  return "�Ҳ�����Ŀ��QQ�Ĺ�ϵ����Ϣ�޷�����";
	case -99:  return "�����õĹ����޷��ڴ˰汾��ʵ��";
	case -101: return "Ӧ�ù���";
	case -102: return "���ǺϷ���Ӧ��";
	case -103: return "���ǺϷ���Ӧ��";
	case -104: return "Ӧ�ò����ڹ�����Information����";
	case -105: return "�޷�����Ӧ����Ϣ";
	case -106: return "�ļ�����Ӧ��ID��ͬ";
	case -107: return "������Ϣ��������";
	case -108: return "AppInfo���ص�Api�汾��֧��ֱ�Ӽ��أ���֧��Api�汾Ϊ9(������)��Ӧ��ֱ�Ӽ���";
	case -109: return "AppInfo���ص�AppID����";
	case -110: return "ȱʧAppInfo���ص�AppID��Ӧ��[Appid].json�ļ�";
	case -111: return "[Appid].json�ļ��ڵ�AppID�����ļ�����ͬ";
	case -120: return "��Api��Ȩ���պ���(Initialize)";
	case -121: return "Api��Ȩ���պ���(Initialize)����ֵ��0";
	case -122: return "���Զ����޸Ŀ�Q�����ļ�����ȡ�����ز��رտ�Q";
	case -150: return "�޷�����Ӧ����Ϣ";
	case -151: return "Ӧ����ϢJson������ʧ�ܣ�����Json���Ƿ���ȷ";
	case -152: return "Api�汾���ɻ����";
	case -153: return "Ӧ����Ϣ��������ȱʧ";
	case -154: return "Appid���Ϸ�";
	case -160: return "�¼�����(Type)�����ȱʧ";
	case -161: return "�¼�����(Function)�����ȱʧ";
	case -162: return "Ӧ�����ȼ���Ϊ10000��20000��30000��40000�е�һ��";
	case -163: return "�¼�����(Api)��֧��Ӧ��Api�汾";
	case -164: return "Ӧ��Api�汾����8����ʹ�����°汾��ͣ�õ��¼�����(Type)��1(������Ϣ)��3(��ʱ��Ϣ)";
	case -165: return "�¼�����Ϊ2(Ⱥ��Ϣ)��4(��������Ϣ)��21(˽����Ϣ)����ȱ��������ʽ(regex)�ı��ʽ����(expression)";
	case -166: return "����Ϊ�յ�������ʽ(regex)��key";
	case -167: return "����Ϊ�յ�������ʽ(regex)�ı��ʽ����(expression)";
	case -168: return "Ӧ���¼�(event)id���������ڻ�Ϊ0";
	case -169: return "Ӧ���¼�(event)id�������ظ�";
	case -180: return "Ӧ��״̬(status)id���������ڻ�Ϊ0";
	case -181: return "Ӧ��״̬(status)period���������ڻ����ô���";
	case -182: return "Ӧ��״̬(status)id�������ظ�";
	case -201: return "�޷�����Ӧ�ã�������Ӧ���ļ�����";
	case -202: return "Api�汾���ɻ����";
	case -997: return "Ӧ��δ����";
	case -998: return "Ӧ�õ�����Auth����֮��� ��Q Api��";
	default:   return "δ֪����,���� ����Py2001 ����������SDK";
	}
}
