#include <iostream>
const int ArSize = 80;
char * left(const char * std, int n = 1);
int main()
{
	using namespace std;
	char sample[ArSize];
	cout << "Please enter a string: \n";
	cin.get(sample, ArSize);
	char * ps = left(sample, 4);
	cout << ps << endl;
	delete[] ps;
	ps = left(sample); //  不传入参数的时候，n的值将会取定为默认参数
	cout << ps << endl;
	delete[] ps;
	while (cin.get() != 'q')
		;
	return 0;
}

char * left(const char * str, int n)
{
	if (n < 0)
		n = 0;
	char * p = new char[n + 1];
	/*
	int m = 0;
	while(m < n && str[m])
		m++;
	避免分配过多的空间(万恶的用户)
	*/
	int i;
	for (i = 0; i < n && str[i]; i++) 
		p[i] = str[i];
	while (i <= n)
		p[i++] = '\0';
	return p;
}
