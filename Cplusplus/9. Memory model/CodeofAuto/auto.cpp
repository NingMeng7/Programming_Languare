/*************************************************************************
    > File Name: auto.cpp
    > Author: JY.ZH
    > Mail: xw2016@mail.ustc.edu.cn 
    > Created Time: 2018年07月18日 星期三 15时41分33秒
 ************************************************************************/

#include<iostream>
using namespace std;

void oil(int x);

int main()
{
	int texas = 31;
	int year = 2011;
	cout << "In main(), texas = " << texas << ", &texas = ";
	cout << &texas << endl;
	cout << "In main(), year = " << year << ", &year = ";
	cout << &year << endl;
	
	oil(texas);

	cout << "In main(), texas = " << texas << ", &texas = ";
	cout << &texas << endl;
	cout << "In main(), year = " << year << ", &year = ";
	cout << &year << endl;
	
	return 0;
}


void oil(int x)
{
	int texas = 5;
	
	cout << "In oil(), texas = " << texas << ", &texas = ";
	cout << &texas << endl;
	cout << "In oil(), x = " << x << ", &x = ";
	cout << &x << endl;

	{
		int texas = 113;
		cout << "In block, texas = " << texas;
		cout << ", &texas = " << &texas << endl;
			cout << "In block, x = " << x << ", &x = ";
		cout << &x << endl;
	}

	cout << "Post-block texas = " << texas;
	cout << ", &texas = " << &texas << endl;
}


