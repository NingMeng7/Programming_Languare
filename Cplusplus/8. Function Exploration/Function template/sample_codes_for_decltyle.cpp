#include <iostream>

int g(int x)
{
	return x;
}
int main()
{
	using namespace std;
	float m = 5.5f;
	float & rm = m;
	decltype(m) v1 = m;
	decltype(rm) v2 = m;
	decltype((m)) v3 = m;
	decltype(g(100)) v4;
	decltype(2.0 * m) v5;

	if (typeid(v1) == typeid(float))
		cout << "1!" << endl;
	if (typeid(v2) == typeid(float &))
		cout << "2!" << endl;
	if (typeid(v3) == typeid(float &))
		cout << "3!" << endl;
	if (typeid(v4) == typeid(int))
		cout << "4!" << endl;
	if (typeid(v5) == typeid(double))
		cout << "5!" << endl;

	while (cin.get() != 'q')
		;
	return 0;
}