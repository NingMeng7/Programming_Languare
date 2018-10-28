#include <iostream>
#include <string>
#include <typeinfo>
union id
{
	long id_num;
	char id_char[20];
};
struct widget
{
	char brand[20];
	int type;
	id id_val;
};


void show(widget prize)
{
	using namespace std;
	cout << prize.brand;
	if (prize.type == 1)
		cout << ": " << prize.id_val.id_num;
	else
		cout << ": " << prize.id_val.id_char;
	cout << endl;
}


int main()
{
	using namespace std;
	widget prize;
	cout << "Please enter the brand name: ";
	cin >> prize.brand;
	cout << "Please enter the id type: 1: long 0: char[] ";
	cin >> prize.type;
	if (prize.type == 1)
		cin >> prize.id_val.id_num;
	else
		cin >> prize.id_val.id_char;
	show(prize);


	while (cin.get() != 'q') {
		;
	}
	return 0;
}