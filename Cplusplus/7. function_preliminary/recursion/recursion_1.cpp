#include <iostream>
void countdown(int n);
int main()
{
	using namespace std;
	countdown(4);
	while (cin.get() != 'q') {
		;
	}
	return 0;
}
void countdown(int n)
{
	using namespace std;
	cout << "Counting down... " << n << "  ( n at " << &n << ")" << endl;
	if (n > 0) {
		countdown(n - 1);
	}
	cout << n << ": Kaboom!" << "	(n at " << &n << ")" << endl;
}

//	��ε����У�statement1 �� statement2 ��ִ��˳���������෴��LIFO�������Կ�������ͬ�ݹ黷�ڵ�n�ǲ�ͬ��
//	�ڵݹ�Ĺ��̸��Ʋ��������ܴ�������ݴ���������������Ϊ�ݹ�̫�����ջ