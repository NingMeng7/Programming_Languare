#include <iostream>
const int limit = 10;
int main()
{
	using namespace std;
	int x;
	cout << "The expression x = 100 has the value: " << (x = 100) << endl;	//  赋值表达式以左侧成员的值作为整体表示式的值

	cout << "Now x = " << x << endl;	// side effect expression value

	cout << "The expression x < 3 has the value: " << (x < 3) << endl;

	cout << "The expression x > 3 has the value: " << (x > 3) << endl;

	cout.setf(ios_base::boolalpha);

	cout << "The expression x < 3 has the value: " << (x < 3) << endl;

	cout << "The expression x > 3 has the value: " << (x > 3) << endl;

	int i, j;
	cout << "The value of (i = 20, j = 2 * i) is: " << (i = 20, j = 2 * i) << endl; //逗号表达式保证先执行计算第一个表达式再计算第二个表达式 
	cout << "The value of i: " << i << endl;        //  C++规定逗号表达式的值是第二部分的值
	cout << "The value of j: " << j << endl;        //  在所有的运算符中，逗号运算符的优先级最低

	while (cin.get() != 'q')
		;
	return 0;
}