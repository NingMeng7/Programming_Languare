#include <iostream>
int main()
{
	using namespace std;
	int var1 = 5;
	const int var2 = 10;
	int const * p1 = &var1;
	const int * p2 = &var1;	// 从程序来看这两个声明是一样的? const的都是 (*p) 指向的对象不能变
	
	int * const p3 = &var1;	// const指针，指向不能变，const的是p3
	
	cout << "var1 = " << var1 << endl;
	
	cout << "*p1 = " << *p1 << endl;
	//	*p1 = 10;	//invaild,ËµÃ÷²»ÄÜÍ¨¹ýp1À´ÐÞ¸Ävar1
	p1 = &var2;	//	valid
	cout << "*p1 = " << *p1 << endl;
	
	cout << "*p2 = " << *p2 << endl;
	//*p2 = 10;	//invalid
	p2 = &var2; //	valid
	cout << "*p2 = " << *p2 << endl;

	cout << "*p3 = " << *p3 << endl;
	*p3 = 12;
	cout << "*p3 = " << *p3 << endl;
	//p3 = &var2;	invalid
	while (cin.get() != 'q')
		;
	return 0;
}
