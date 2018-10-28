#include <iostream>
#include "namesp.h"
void other(void);
void another(void);
int main(void)
{
	using debt::Debt;	//	makes the Debt structure definition available
	using debt::showDebt;	//	makes the showDebt function available 
	Debt golf = { {"Benny", "Goatsniff"}, 120.0 };
	showDebt(golf);
	other();
	another();
	while (std::cin.get() != 'q')
		;
	return 0;
}

void other(void)	// 使用using编译指令
{
	using std::cout;
	using std::endl;
	using namespace debt;	// also makes pers namespace available
	Person dg = { "Doodles", "Glister" };
	showPerson(dg);
	cout << endl;
	Debt zippy[3];
	int i;
	for (i = 0; i < 3; i++)
		getDebt(zippy[i]);

	for (i = 0; i < 3; i++)
		showDebt(zippy[i]);

	cout << "Total debt: $" << sumDebt(zippy, 3) << endl;
	return;
}

void another(void)	//	使用域解析运算符访问
{
	using pers::Person;
	Person collector = { "Milo", "Rightshift" };
	pers::showPerson(collector);
	std::cout << std::endl;
}
