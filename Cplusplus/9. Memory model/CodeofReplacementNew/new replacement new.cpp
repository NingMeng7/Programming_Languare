#include <iostream>
#include <new>

const int BUF = 512;
const int N = 5;
char buffer[BUF];

int main()
{
	using namespace std;
	double *pd1, *pd2;
	int i;
	cout << "Calling new and placement new: " << endl;
	pd1 = new double[N];
	pd2 = new (buffer) double[N];
	for (i = 0; i < N; i++)
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	cout << "Memory addresses: \n" << " heap: " << pd1 << " static: " << (void *)buffer << endl;
	cout << "Memory contents:" << endl;
	for (int i = 0; i < N; i++) {
		cout << pd1[i] << " at" << &pd1[i] << "; ";
		cout << pd2[i] << " at" << &pd2[i] << endl;
	}

	cout << "\nCalling new and placement new a second time:" << endl;
	double *pd3, *pd4;
	pd3 = new double[N];
	pd4 = new(buffer) double[N];
	for (i = 0; i < N; i++)
		pd3[i] = pd4[i] = 1000 + 40.0 * i;
	cout << "Memory contents:\n";
	for (i = 0; i < N; i++) {
		cout << pd3[i] << " at" << &pd3[i] << "; ";
		cout << pd4[i] << " at" << &pd4[i] << endl;
	}

	cout << "\nCalling new and placement new a third time:\n";
	delete[]pd1;
	pd1 = new double[N];	//	deleteֻ�ͷſռ�,ָ�뱣��
	pd2 = new (buffer + N * sizeof(double)) double[N];	//	���Զ���ʼλ�ü�һ������
	for (i = 0; i < N; i++)
		pd2[i] = pd1[i] = 1000 + 60.0 * i;
	cout << "Memory contents:" << endl;
	for (i = 0; i < N; i++) {
		cout << pd1[i] << " at" << &pd1[i] << "; ";
		cout << pd2[i] << " at" << &pd2[i] << endl;
	}
	delete[]pd1;	//	delete ֻ�ܶ�ʹ�ó���new����Ķ����ڴ�ʹ��
	delete[]pd3;
	while (cin.get() != 'q')
		;
	return 0;
}
