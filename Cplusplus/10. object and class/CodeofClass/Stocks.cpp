//	This file shows two ways to create new object

#include <iostream>
#include "stock.h"

int main()
{
	{
		using std::cout;
		using std::endl;
		
		cout << "Using constructor to create new object:\n";
		Stock stock1("NanoSmart", 12, 20.0);
		stock1.show();
		
		Stock stock2 = Stock("Boffo Objects", 2, 2.0);	
		stock2.show();

		cout << "Assigning stock1 to stock2:\n";
		stock2 = stock1;	//	类之间的直接赋值是合法的
		cout << "Listing stock1 and stock2: " << endl;
		stock1.show();
		stock2.show();

		cout << "Using a constructor to reset an object \n";
		stock1 = Stock("Nifty Foods", 10, 50.0);	//	从运行结果可以看出这里编译器创建了一个临时对象
		cout << "Revised stock1:\n";
		stock1.show();
		cout << "Done\n";
	}	//	Code segment set on purpose for the demo of destructor
	//	destructor 调用的顺序其实反应了自动变量是通过栈来管理的事实, 因此Stock1先进后出

	while (std::cin.get() != 'q')
		;
	return 0;
}
