#pragma once
const int Len = 40;	//	const ��ʹ�ñ����������Ա�Ϊ�ڲ�����˿��Է���ͷ�ļ���
struct golf {
	char fullname[Len];
	int handicap;
};
void setgolf(golf & g, const char * name, int hc);
int setgolf(golf & g);
void handicap(golf & g, int hc);
void showgolf(const golf & g);
