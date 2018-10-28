#pragma once
const int Len = 40;	//	const 将使得变量的链接性变为内部，因此可以放在头文件中
struct golf {
	char fullname[Len];
	int handicap;
};
void setgolf(golf & g, const char * name, int hc);
int setgolf(golf & g);
void handicap(golf & g, int hc);
void showgolf(const golf & g);
