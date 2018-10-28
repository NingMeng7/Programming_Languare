#include <iostream>
#include <string>
const int limit = 10;
int main()
{
	using namespace std;
	char temp;

	for (int i = 0; i < limit; i++) {	//  for 是入口条件循环
		cout << i << endl;
	}
	//cout << i;	invalid,在for循环中声明的变量i离开for循环后消失
	cout << endl;

	for (int i = 0; i < limit; i += 2) {	//	步长
		cout << i << endl;
	}

	if (limit == 10) {
		int y = 100;
		cout << "The value of y: " << y << endl;	//	语句块内部的变量y将会屏蔽外部变量y(如果有的话)
	}
	//cout << y;	invalid,在复合语句块中声明的变量y在离开语句块后消失
	cout << endl;

	string word = "abcdefghijk";
	cout << "Before reverse:" << endl;
	cout << word << endl;
	for (int j = 0, i = word.size() - 1; j < i; ++j, --i) {
		temp = word[i];
		word[i] = word[j];
		word[j] = temp;
	}
	cout << "After reverse: " << endl;
	cout << word << endl;

	while (cin.get() != 'q')
		;
	return 0;
}