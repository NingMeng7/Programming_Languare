#include <iostream>
#include "Stock20.h"

const int STKS = 4;

int main()
{
	Stock stocks[STKS] = {	//	为每个元素调用构造函数
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("MOnolithic Obelisks", 130, 3.25),
		Stock("FLeep Enterprises", 60, 6.5)
	};

	/*
	Stock stocks[STKS] = {	//	为每个元素调用不同的构造函数
		Stock("NanoSmart", 12),
		Stock(),
		Stock("MOnolithic Obelisks", 130, 3.25),
	}
	首先使用默认构造函数创建数组元素，然后花括号的构造函数将会创建临时对象，然后将临时对象的内容赋值到相应的元素。	这说明，要创建类的对象数组，类必须要有默认构造函数。
	 */
	
	Stock test;	//	This may raise an error.

	std::cout << "Stock holdings\n";
	
	int st;
	
	for (st = 0; st < STKS; st++) 
		stocks[st].show();
	
	const Stock * top = &stocks[0];
	
	for (st = 1; st < STKS; st++)	//	Show how this pointer works
		top = &top->topval(stocks[st]);
	
	std::cout << "\nMost valuable holding:\n";
	top->show();
	return 0;
}
