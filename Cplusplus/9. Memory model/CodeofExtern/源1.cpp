#include <iostream>
extern double warming;	//	use warming from another file

void update(double dt);
void local();

using std::cout;
void update(double dt)
{
	extern double warming;
	warming += dt;
	cout << "Updating global warming to " << warming;
	cout << " degress" << std::endl;
}

void local()
{
	double warming = 0.8;
	cout << "Local warming = " << warming << " degress." << std::endl;
	cout << "But global warming = " << ::warming;	//	�����ȫ�ֱ��������Σ�ʹ��ȫ�ֱ���
	cout << " deress." << std::endl;
}
