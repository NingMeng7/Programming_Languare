#include <iostream>
const int ArrSize = 8;
int sumarr(const int * begin, const int * end);
int main()
{
	using namespace std;
	int cookies[ArrSize] = { 1,2,4,8,16,32,64,128 };

	int sum = sumarr(cookies, cookies + ArrSize);
	cout << "Total cookies eaten: " << sum << endl;
	cout << "First three eaters ate: " << sumarr(cookies, cookies + 3) << endl;
	cout << "Last four eaters ate: " << sumarr(cookies + 4, cookies + 8);
	while (cin.get() != 'q') {
		;
	}
	return 0;
}


int sumarr(const int * begin, const int * end)	//	���������ֹͨ�����ָ������ݾ����޸ģ���������
{
	const int * pt;	//	��ָ��ָ��һ����������ֹ(ͨ��ָ��!!!)�޸������,�����������ܱ�ͨ��������ʽ�����޸ģ�
					//	��˵�������ĵ�ַ���Ը���constָ�룬ͬʱ���ָ�뱾���ָ���ǿɱ�ģ�������Ȼ������ͨ�����޸ı���ֵ
					//  C++��ֹ��const�����ĵ�ַ������cosntָ�룬�� const a = 10;  int * p = &a; �ǷǷ��ģ�����
					//	�� const a = 10; const int * p = &a; �ǺϷ��ģ�����

					//	int a = 3;	int * const p = &a;	���������ʽʹ��pֻ��ָ��a!!!
	int total = 0;
	for (pt = begin; pt != end; pt++) {
		total += *pt;
	}
	return total;
}