//	�ڴ����������£����ǰ���������ָ���ͬ����������sizeof���Լ�ͨ������ָ���ܽ����޸ģ����������ǳ���
//	&array ��&array[0] �ǲ�ͬ�ģ��������ǵ�ֵ��ȣ������ڽ���+2�����ʱ��ǰ�߼ӵ���2*(sizeof array)�����߼ӵ���2*int(����array��int����)
#include <iostream>

int main()
{
	using namespace std;
	int * p = new int[10];	//  psomeָ��10��intֵ�ڴ���еĵ�һ��Ԫ��
	for (int i = 0; i < 10; i++) {
		p[i] = i;
	}
	for (int i = 0; i < 10; i++) {
		cout << p[i] << "  ";
	}
	delete[] p;

	cout << endl;

	double wages[3] = { 10000.0, 20000.0, 30000.0 };
	short stacks[3] = { 3, 2, 1 };
	double *pd = wages;
	short *ps = &stacks[0];

	for (; pd <= &wages[2]; pd++) {
		cout << *pd << "  ";
	}

	cout << endl;

	for (; ps <= &stacks[2]; ps++) {
		cout << *ps << "  ";
	}

	cout << endl;

	cout << "size of wages: " << sizeof wages << endl;	//	����Ŀռ�
	cout << "size of pd: " << sizeof pd << endl;	//	pdռ���ֽڳ���

	while (cin.get() != 'q')
		;
	return 0;
}