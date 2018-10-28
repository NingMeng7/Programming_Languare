#include <iostream>
template <typename T>
void Swap(T &a, T &b);	//  声明模板并没有声明任何函数！

struct job
{
	char name[40];
	double salary;
	int floor;
};

template <> void Swap<job>(job &j1, job &j2);
void show(job &j);

int main()
{
	using namespace std;
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10, j = 20;
	cout << "i, j = " << i << ", " << j << endl;
	cout << "After swaping: " << endl;
	Swap(i, j);	//  隐式实例化
	cout << "i, j = " << i << ", " << j << endl;

	job sue = { "Susan Yaffee", 73000.60, 7 };
	job sidney = { "Sidney Taffee", 78060.72, 9 };
	cout << "Before job swapping: " << endl;
	show(sue);
	show(sidney);
	Swap(sue, sidney);
	cout << "After job swapping:" << endl;
	show(sue);
	show(sidney);
	while (cin.get() != 'q')
		;
	return 0;
}

template <typename T>
void Swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <> void Swap<job>(job &j1, job &j2)	//  显示具体化
{
	double t1;
	int t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;
	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}

void show(job &j)
{
	using namespace std;
	cout << j.name << ": $" << j.salary << " on floor " << j.floor << endl;
}