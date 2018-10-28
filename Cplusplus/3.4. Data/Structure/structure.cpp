#include <iostream>
struct inflatable
{
	char name[20];
	float volume;
	double price;
};

int main()
{
	using namespace std;
	inflatable guest =  //  C++允许在声明结构体变量的时候省略struct
	{                   //  结构体允许列表初始化 = {} 将会把所有的成员赋值成0
		"Glorious Gloria",
		1.88,
		29.99
	};

	inflatable pal =
	{
		"Audacious Arthur",
		3.12,
		32.99
	};

	cout << "Expand your guest list with " << guest.name;   //  允许用成员运算符(.)来访问各个成员
	cout << " and " << pal.name << "!\n";
	cout << "You can have both for $";
	cout << guest.price + pal.price << "!\n";

	inflatable guests[2] =  //  结构作为新定义的一种变量可以声明数组 
	{
		{ "Bambi", 0.5, 21.99 },
	{ "Godzilla", 2000, 565.99 }
	};

	cout << "The guests " << guests[0].name << " and " << guests[1].name << "have a combined volume of "
		<< guests[0].volume + guests[1].volume << " cubic feet.\n";


	pal = guest;  //  结构体可以彼此赋值，哪怕结构成员可能有数组


	return 0;
}