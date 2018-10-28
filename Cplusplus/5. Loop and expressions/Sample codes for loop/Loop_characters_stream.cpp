#include <iostream>
int main()
{
	using namespace std;
	char ch;
	int count = 0;
	cout << "Please enter the text and quit with #: " << endl;
	cin >> ch;
	while (ch != '#') {	//  blank,制表符,回车都不会被计入
		cout << ch;
		++count;
		cin >> ch;
	}
	cout << endl << count << " characters read\n";

	cin.ignore(1024, '\n');	//	将上一段程序的结尾回车影响消除

	count = 0;
	cout << "Please enter the text and quit with #: " << endl;
	cin.get(ch);	//	get可以得到输入的下一个字符，包括空格
	while (ch != '#') {
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << " characters read\n";


	cin.ignore(1024, '\n');	//	将上一段程序的结尾回车影响消除


	count = 0;
	cout << "Please enter the text and quit with EOF: " << endl;
	cin.get(ch);
	while (cin.fail() == false) {	//  quit with EOF(Ctrl+Z)
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << " characters read \n";


	cin.ignore(1024, '\n');	//	将上一段程序的结尾回车影响消除
	cin.clear();

	count = 0;
	cout << "Please enter the text and quit with EOF: " << endl;
	while (cin.get(ch)) {	//	cin.get()这个表达式的值是你输入的那个字符
		cout << ch;	//	cin可以作为bool值，当最后一次读取成功，cin==true,而cin.get(char)的返回值是cin，因此可以简化程序像这样
		++count;
	}
	cout << endl << count << " characters read \n";
	cin.clear();
	while (cin.get() != 'q') {
		;
	}
	return 0;
}