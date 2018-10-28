/*************************************************************************
    > File Name: stone.cpp
    > Author: JY.ZH
    > Mail: xw2016@mail.ustc.edu.cn 
    > Created Time: 2018年07月20日 星期五 12时31分10秒
 ************************************************************************/

#include<iostream>
using std::cout;
#include "stonewt.h"
void display(const Stonewt & st, int n);

int main()
{
	Stonewt incognito = 275;
	Stonewt wolfe(285.7);
	Stonewt tatf(21, 8);
	Stonewt poppins(9, 2.8);
	double p_wt = poppins;
	cout << "Convert to double => ";
	cout << "Poppins: " << p_wt << " pounds.\n";
	cout << "Convert to int => ";
	cout << "Poppins: " << int (poppins) << " pounds.\n";

	cout << "The celebrity weighed: ";
	incognito.show_stn();
	cout << "The detective weighed: ";
	wolfe.show_stn();
	cout << "The President weighed: ";
	tatf.show_lbs();

	incognito = 276.8;
	tatf = 325;
	cout << "After dinner, the celebrity weighed: ";
	incognito.show_stn();
	cout << "After dinner, the President weighed: ";
	tatf.show_lbs();
	display(tatf, 2);
	cout << "The wrestler weighed even more.\n";
	display(422, 2);
	cout << "No stone left unearned\n";
	return 0;
}

void display(const Stonewt & st, int n) 
{
	for (int i = 0; i < n; i++) {
		cout << "Wow! ";
		st.show_stn();
	}
}
