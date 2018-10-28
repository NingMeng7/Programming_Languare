//	利用一个函数来接收不同长短的字符串，用指针来指向他们
//	指针与结构体配合使用，既可以直接声明一个结构体的指针，然后通过new给这个指针分配内存空间来创造一个结构体
//	也可以声明一个结构体，然后声明一个指针指向这个结构体
#include <iostream>
#include <cstring>
#define MaxLength 80
struct inflatable
{
	char* name;
	float volume;
	double price;
};
void show(inflatable * ps)
{
	using namespace std;
	cout << "name: " << ps->name << endl;
	cout << "volume: " << ps->volume << endl;
	cout << "price: " << ps->price << endl;
}
char * getname()
{
	using namespace std;
	char temp[MaxLength];
	cout << "Please enter the name: ";
	cin.get(temp, MaxLength);
	char* pn = new char[strlen(temp) + 1];
	strcpy_s(pn, strlen(temp) + 1, temp);
	return pn;
}
int main()
{
	using namespace std;
	inflatable * ps = new inflatable;
	ps->name = getname();
	cout << "Please enter the volume in cuic feet: ";
	cin >> ps->volume;
	cout << "Please enter the price: ";
	cin >> ps->price;
	show(ps);
	delete[] ps->name;	// 注意，这个写法把new和delete写在了两个函数，应当记得释放内存
	delete ps;

	while (cin.get() != 'q')
		;
	return 0;
}