/*************************************************************************
    > File Name: usetime0.cpp
    > Author: JY.ZH
    > Mail: xw2016@mail.ustc.edu.cn 
    > Created Time: 2018年07月19日 星期四 18时51分43秒
 ************************************************************************/

#include <iostream>
#include "mytime0.h"

int main()
{
	using std::cout;
	using std::endl;
	Time planning;
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;

	cout << "Planning time = ";
	planning.Show();
	cout << endl;

	cout << "Coding time = ";
	coding.Show();
	cout << endl;
	
	cout << "Fixing time = ";
	fixing.Show();
	cout << endl;

	total = coding.Sum(fixing);
	cout << "Total time = ";
	total.Show();
	cout << endl;

	return 0;
}
