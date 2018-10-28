#include <iostream>
#include "golf.h"
#include <cstring>
Golf::Golf()
{
	strncpy(fullname,"no name", Len);
	handicap = 0;
}

Golf::Golf(const char * name, int hc)
{
	strncpy(fullname, name, Len);
	handicap = hc;
}

void Golf::setgolf(const char * name, int hc)
{
	strncpy(fullname, name, Len);
	handicap = hc;
}
/*
int Golf::setgolf()
{
	using std::cout;
	using std::cin;
	cout << "PLease enter the name: ";
	getline(cin, fullname);
	cout << "Please enter the handicap: ";
	cin >> handicap;
	return 0;
}
*/

void Golf::sethandicap(int hc)
{
	handicap = hc;
}

void Golf::showgolf() const
{
	using std::cout;
	using std::endl;
	cout << "Full name: " << fullname << endl;
	cout << "handicap: " << handicap << endl;
}

