#include <iostream>
using namespace std;
enum { red, orange, yellow, green, blue, violet, indigo };
int main()
{
	cout << "Please enter the color code(0~6): ";
	int code;
	cin >> code;
	while (code >= red && code <= indigo) { //  enum可以被强制转换为int
		switch (code)
		{
		case red:		cout << "red" << endl;	break;
		case orange:	cout << "orange" << endl;	break;
		case yellow:	cout << "yellow" << endl;	break;
		case green:		cout << "grenn" << endl;	break;
		case blue:		cout << "blue" << endl;		break;
		case violet:	cout << "violet" << endl;	break;
		case indigo:	cout << "indigo" << endl;	break;
		}
		cout << "Please enter the color code(1~6): ";
		cin >> code;
	}
	cout << "Bye!" << endl;
	return 0;
}