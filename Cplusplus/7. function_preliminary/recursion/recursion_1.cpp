#include <iostream>
void countdown(int n);
int main()
{
	using namespace std;
	countdown(4);
	while (cin.get() != 'q') {
		;
	}
	return 0;
}
void countdown(int n)
{
	using namespace std;
	cout << "Counting down... " << n << "  ( n at " << &n << ")" << endl;
	if (n > 0) {
		countdown(n - 1);
	}
	cout << n << ": Kaboom!" << "	(n at " << &n << ")" << endl;
}

//	五次调用中，statement1 和 statement2 的执行顺序是正好相反的LIFO！！可以看到，不同递归环节的n是不同的
//	在递归的过程复制参数开销很大，如果传递大容量参数容易因为递归太深而爆栈