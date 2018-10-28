#include <iostream>
template <typename T>	//	template <class T>
void Swap(T &a, T &b);

int main()
{
	using namespace std;
	int i = 10;
	int j = 20;
	cout << "i, j = " << i << ", " << j << endl;
	Swap(i, j);
	cout << "After swaping we get: " << endl;
	cout << "i, j = " << i << ", " << j << endl;

	cout << endl;

	double x = 24.5;
	double y = 81.7;
	cout << "x, y = " << x << ", " << y << endl;
	Swap(x, y);
	cout << "After swaping we get: " << endl;
	cout << "x, y = " << x << ", " << y << endl;
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