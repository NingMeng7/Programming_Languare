#include <iostream>
const int ArrSize = 8;
int sumarr(const int * begin, const int * end);
int main()
{
	using namespace std;
	int cookies[ArrSize] = { 1,2,4,8,16,32,64,128 };

	int sum = sumarr(cookies, cookies + ArrSize);
	cout << "Total cookies eaten: " << sum << endl;
	cout << "First three eaters ate: " << sumarr(cookies, cookies + 3) << endl;
	cout << "Last four eaters ate: " << sumarr(cookies + 4, cookies + 8);
	while (cin.get() != 'q') {
		;
	}
	return 0;
}


int sumarr(const int * begin, const int * end)	//	这个声明防止通过这个指针对数据就行修改，保护数据
{
	const int * pt;	//	将指针指向一个常量，防止(通过指针!!!)修改这个量,这个量本身可能被通过其他形式进行修改，
					//	这说明变量的地址可以赋给const指针，同时这个指针本身的指向是可变的，但是仍然不可以通过它修改变量值
					//  C++禁止将const变量的地址赋给非cosnt指针，即 const a = 10;  int * p = &a; 是非法的！！！
					//	而 const a = 10; const int * p = &a; 是合法的！！！

					//	int a = 3;	int * const p = &a;	这个声明方式使得p只能指向a!!!
	int total = 0;
	for (pt = begin; pt != end; pt++) {
		total += *pt;
	}
	return total;
}