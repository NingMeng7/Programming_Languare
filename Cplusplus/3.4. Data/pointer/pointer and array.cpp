//	在大多数的情况下，我们把数组名和指针等同起来，除了sizeof，以及通常而言指针能进行修改，而数组名是常量
//	&array 与&array[0] 是不同的，尽管他们的值相等，但是在进行+2运算的时候，前者加的是2*(sizeof array)，后者加的是2*int(假设array是int数组)
#include <iostream>

int main()
{
	using namespace std;
	int * p = new int[10];	//  psome指向10个int值内存块中的第一个元素
	for (int i = 0; i < 10; i++) {
		p[i] = i;
	}
	for (int i = 0; i < 10; i++) {
		cout << p[i] << "  ";
	}
	delete[] p;

	cout << endl;

	double wages[3] = { 10000.0, 20000.0, 30000.0 };
	short stacks[3] = { 3, 2, 1 };
	double *pd = wages;
	short *ps = &stacks[0];

	for (; pd <= &wages[2]; pd++) {
		cout << *pd << "  ";
	}

	cout << endl;

	for (; ps <= &stacks[2]; ps++) {
		cout << *ps << "  ";
	}

	cout << endl;

	cout << "size of wages: " << sizeof wages << endl;	//	数组的空间
	cout << "size of pd: " << sizeof pd << endl;	//	pd占的字节长度

	while (cin.get() != 'q')
		;
	return 0;
}