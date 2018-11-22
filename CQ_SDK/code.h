#pragma once

#include "face.h"

#include <string>

inline
namespace CQ {
	//TODO::���codeδ��д
	struct code {
		//[CQ:image,file={1}] - �����Զ���ͼƬ
		//�ļ��� ��QĿ¼\data\image\ Ϊ����
		static std::string image(std::string fileurl);

		//[CQ:record,file={1},magic={2}] - ��������
		//�ļ��� ��QĿ¼\data\record\ Ϊ����
		static std::string record(std::string fileurl, bool magic = false);
		//[CQ:record,file={1},magic={2}] - ��������
		//�ļ��� ��QĿ¼\data\record\ Ϊ����
		//�˺����������ϵͳ�����ϳɽ�wantSpeak�ϳɵ�ָ���ļ�
		//static std::string record(std::string fileurl, std::string wantSpeak, bool magic = false);

		//[CQ:face,id={1}] - QQ����
		static std::string face(int faceid);

		//[CQ:face,id={1}] - QQ����
		static std::string face(CQ::face face);
		
		//[CQ:at,qq={1}] - @ĳ��
		static std::string at(long long QQ);

		//[CQ:effect,type=art,id=2003,content=С��] - ħ������
		static std::string effect(std::string type, int id, std::string content);

		//[CQ:sign,title=ɹ�Ҹ�,image=http://pub.idqqimg.com/pc/misc/files/20170825/cc9103d0db0b4dcbb7a17554d227f4d7.jpg] - ǩ��
		static std::string sign(std::string title, std::string imageUrl);

		//[CQ:hb, title = ��ϲ����] - ���(ֻ����,���ܷ�)

		//[CQ:shake, id = 1] - ��һ��(ԭ���ڶ�������֧�ֺ�����Ϣʹ��)

		//[CQ:sface,id={1}] - С����

		//[CQ:bface,id={1}] - ԭ������

		//[CQ:emoji,id={1}] - emoji����

		//[CQ:rps,type={1}] - ���Ͳ�ȭħ������
		//���Ͳ�֧���Զ���type
		//1 Ϊ ʯͷ
		//2 Ϊ ����
		//3 Ϊ ��

		//[CQ:dice,type={1}] - ����������ħ������
		//���Ͳ�֧���Զ���type
		//typeΪ���ӵ���

		//[CQ:anonymous,ignore={1}] - ��������Ϣ(��֧��Ⱥ��Ϣʹ��)
		//��������Ϣ�ͷ
		//ignoreΪtrueʱ,�������ʧ����תΪ��ͨ��Ϣ
		static std::string anonymous(bool ignore);

		//[CQ:music,type={1},id={2}] - ��������
		//typeΪ����ƽ̨,֧��qq��163��xiami
		//id��Ϊ����id

		//[CQ:music,type=custom,url={1},audio={2},title={3},content={4},image={5}] - ���������Զ������
		//urlΪ��������,������������������ҳ�棨���������ҳ��
		//audioΪ��Ƶ���ӣ���mp3���ӣ�
		//titleΪ���ֵı��⣬����12������
		//contentΪ���ֵļ�飬����30�����ڡ��ò����ɱ�����
		//imageΪ���ֵķ���ͼƬ���ӡ�������Ϊ�ջ򱻺��ԣ�����ʾĬ��ͼƬ
		//!�����Զ������ֻ����Ϊ������һ����Ϣ����

		//[CQ:share,url={1},title={2},content={3},image={4}] - �������ӷ���
		//urlΪ�������ӡ�
		//titleΪ����ı��⣬����12�����ڡ�
		//contentΪ����ļ�飬����30�����ڡ��ò����ɱ����ԡ�
		//imageΪ�����ͼƬ���ӡ�������Ϊ�ջ򱻺��ԣ�����ʾĬ��ͼƬ��
		//!���ӷ���ֻ����Ϊ������һ����Ϣ����
	};
}