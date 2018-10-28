#include <iostream>
template <typename T>
void Swap(T &a, T &b);

template <typename T>
void Swap(T *a, T *b, int n);

void show(int a[]);
const int Lim = 8;
int main()
{
	using namespace std;
	int i = 10, j = 20;
	cout << "i, j = " << i << ", " << j << endl;
	cout << "After swaping: " << endl;
	Swap(i, j);
	cout << "i, j = " << i << ", " << j << endl;

	int d1[Lim] = { 0, 9, 7, 32, 2, 2 ,3, 4 };
	int d2[Lim] = { 1,2,3,4,5,6,7,8 };
	cout << "Original arrays:" << endl;
	show(d1);
	show(d2);
	Swap(d1, d2, Lim);
	cout << "After swaping: " << endl;
	show(d1);
	show(d2);
	while (cin.get() != 'q')
		;
	return 0;
}

template <typename T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T>
void Swap(T a[], T b[], int n)	//	不是所有模板的参数都要是泛型的参数哦
{
	T temp;
	for (int i = 0; i < n; i++) {
		temp = a[i];
		a[i] = b[i];
		b[i] = temp;
	}
}

void show(int a[])
{
	using namespace std;
	cout << a[0] << a[1] << "/";
	cout << a[2] << a[3] << "/";
	for (int i = 4; i < Lim; i++)
		cout << a[i];
	cout << endl;
}