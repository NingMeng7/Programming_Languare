#include <iostream>
const int limit = 10;
int main()
{
	using namespace std;
	int x;
	cout << "The expression x = 100 has the value: " << (x = 100) << endl;	//  ��ֵ���ʽ������Ա��ֵ��Ϊ�����ʾʽ��ֵ

	cout << "Now x = " << x << endl;	// side effect expression value

	cout << "The expression x < 3 has the value: " << (x < 3) << endl;

	cout << "The expression x > 3 has the value: " << (x > 3) << endl;

	cout.setf(ios_base::boolalpha);

	cout << "The expression x < 3 has the value: " << (x < 3) << endl;

	cout << "The expression x > 3 has the value: " << (x > 3) << endl;

	int i, j;
	cout << "The value of (i = 20, j = 2 * i) is: " << (i = 20, j = 2 * i) << endl; //���ű��ʽ��֤��ִ�м����һ�����ʽ�ټ���ڶ������ʽ 
	cout << "The value of i: " << i << endl;        //  C++�涨���ű��ʽ��ֵ�ǵڶ����ֵ�ֵ
	cout << "The value of j: " << j << endl;        //  �����е�������У���������������ȼ����

	while (cin.get() != 'q')
		;
	return 0;
}