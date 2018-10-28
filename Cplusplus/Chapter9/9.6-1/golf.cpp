#include <iostream>
#include "golf.h"
void setgolf(golf & g, const char * name, int hc)
{
	strncpy_s(g.fullname, name, Len);
	g.handicap = hc;
}

int setgolf(golf & g)
{
	using std::cout;
	using std::cin;
	using std::endl;
	cout << "Please enter the name of the golfer: " << endl;
	cin.get(g.fullname, Len);
	if (g.fullname[0] == '\0') {
		cin.clear();
		return 0;
	}
	cout << "Please enter the handicap of the golfer: " << endl;
	while (!(cin >> g.handicap)) {
		cin.clear();
		while (cin.get() != '\n')
			continue;
		cout << "Bad input, please enter an integer!" << endl;
	}
	while (cin.get() != '\n')	//	把回车清除
		;
	return 1;
}

void handicap(golf & g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf & g)
{
	using std::cout;
	using std::endl;
	cout << "Name: " << g.fullname << endl;
	cout << "Handicap: " << g.handicap << endl;
}
