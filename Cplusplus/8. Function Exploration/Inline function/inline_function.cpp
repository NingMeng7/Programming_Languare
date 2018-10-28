#include <iostream>

inline double square(double x) { return x * x; }

int main()
{
	using namespace std;
	double a, b;
	double c = 13.0;

	a = square(5.0);
	b = square(4.5 + 7.5);
	cout << "a = " << a << ", b = " << b << "\n";
	cout << "c = " << c;
	cout << ", c squared = " << square(c++) << "\n";
	cout << "Now c = " << c << "\n";
	while (cin.get() != 'q')
		;
	return 0;
}


#define SQUARE(X) X*X

a = SQUARE(5.0);         ~  a = 5.0*5.0;
a = SQUARE(4.5 + 7.5);   ~  a = 4.5 + 7.5 * 4.5 * 7.5;
a = SQUARE(c++);	 ~  a = c++*c++;

而从上面函数运行结果来看，内联函数的参数为表达式的时候，内联函数传递的是表达式的值，这使得内联函数的功能比宏定义要强得多。
