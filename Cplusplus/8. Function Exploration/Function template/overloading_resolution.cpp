#include <iostream>

template <typename T>
void showarray(T arr[], int n);

template <typename T>
void showarray(T * arr[], int n);

struct debts
{
	char name[50];
	double amount;
};

int main()
{
	using namespace std;
	int things[6] = { 13, 31, 103, 301, 310, 130 };
	struct debts mr_E[3] = {
		{ "Ima Wolfe", 2400.0 },
	{ "Ura Foxe", 1300.9 },
	{ "Iby Stout", 1800.0 }
	};
	double * pd[3];	//	ָ������

	for (int i = 0; i < 3; i++) {
		pd[i] = &mr_E[i].amount;
	}

	cout << "Listening Mr.E's counts of things:" << endl;
	showarray(things, 6);	//	ģ��A	
	cout << "Listing Mr/E's debts:" << endl;
	showarray(pd, 3);	//	ģ��A��B������ȫƥ�䣬����ģ��B����������������ָ��ľ�����裬���B�����ƥ��
	while (cin.get() != 'q')
		;
	return 0;
}

template <typename T>
void showarray(T arr[], int n)
{
	using namespace std;
	cout << "template A" << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

template <typename T>
void showarray(T * arr[], int n)
{
	using namespace std;
	cout << "template B" << endl;
	for (int i = 0; i < n; i++)
		cout << *arr[i] << ' ';
	cout << endl;
}