#include <iostream>
using namespace std;
void other();
void another();
int x = 10;
int y;

int main()
{
	cout << x << endl;	//	10
	{
		int x = 4;	//	代码块中的自动变量
		cout << x << endl;	//	4
		cout << y << endl;	//	???	
	}
	other();
	another();
	while (cin.get() != 'q')
		;
	return 0;
}

void other()
{
	int y = 1;
	cout << "Other: " << x << ", " << y << endl;	//	10, 1
}
