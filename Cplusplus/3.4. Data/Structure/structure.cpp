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
	inflatable guest =  //  C++�����������ṹ�������ʱ��ʡ��struct
	{                   //  �ṹ�������б��ʼ�� = {} ��������еĳ�Ա��ֵ��0
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

	cout << "Expand your guest list with " << guest.name;   //  �����ó�Ա�����(.)�����ʸ�����Ա
	cout << " and " << pal.name << "!\n";
	cout << "You can have both for $";
	cout << guest.price + pal.price << "!\n";

	inflatable guests[2] =  //  �ṹ��Ϊ�¶����һ�ֱ��������������� 
	{
		{ "Bambi", 0.5, 21.99 },
	{ "Godzilla", 2000, 565.99 }
	};

	cout << "The guests " << guests[0].name << " and " << guests[1].name << "have a combined volume of "
		<< guests[0].volume + guests[1].volume << " cubic feet.\n";


	pal = guest;  //  �ṹ����Ա˴˸�ֵ�����½ṹ��Ա����������


	return 0;
}