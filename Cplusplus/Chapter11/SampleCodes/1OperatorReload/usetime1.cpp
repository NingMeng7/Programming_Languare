/*************************************************************************
 *
    > File Name: usetime1.cpp
    > Author: JY.ZH
    > Mail: xw2016@mail.ustc.edu.cn 
    > Created Time: 2018年07月19日 星期四 19时04分09秒
 ************************************************************************/

#include <iostream>
#include "mytime1.h"

int main()
{
	using std::cout;
	using std::endl;
	Time weeding(4, 35);
	Time waxing(2, 47);
	Time total;
	Time diff;
	Time adjusted;

	cout << "Weeding time = ";
	weeding.Show();
	cout << endl;

	cout << "Waxing time = ";
	waxing.Show();
	cout << endl;

	cout << "Total work time = ";
	total = weeding + waxing;
	total.Show();
	cout << endl;

	diff = weeding - waxing;
	cout << "Weeding time - Waxing time = ";
	diff.Show();
	cout << endl;

	adjusted = total * 1.5;
	cout << "Adjusted work time = ";
	adjusted.Show();
	cout << endl;

	return 0;
}
