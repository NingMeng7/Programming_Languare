/*	ͨ����ͷ�ļ��а���:
 *	����ԭ��
 *	�ṹ����
 *	#define ���� const����ķ��ų���
 *	������
 *	ģ������
 *	��������
 */




#ifndef COORDIN_H_	//	ֻ����ǰû��ʹ��Ԥ�������ָ��#define ��������COORDIN_H_�Ŵ���ifdef endif ������
#define COORDIN_H_	//	������������ܷ�ֹ�������ͷ�ļ����Σ��������ܹ�ʹ�ñ��������Զ���İ���

struct polar {
	double distance;
	double angle;
};

struct rect {
	double x;
	double y;
};

polar rect_to_polar(rect xypos);
void show_polar(polar dapos);

#endif
