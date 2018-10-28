#include <iostream>
#include <string>
#include "person.h"
#include <cstring>
//	不能直接赋值，并不是执行到才初始化类的变量
Person::Person(const std::string &ln, const char * fn)
{
	lname = ln;
	strncpy(fname, fn, LIMIT);
}

void Person::show() const
{
	using std::cout;
	using std::endl;
	cout << "fname: " << fname << endl;
	cout << "lastname: " << lname << endl;
}

void Person::Formalshow() const
{
	using std::cout;
	using std::endl;
	cout << "lastname: " << lname << endl;
	cout << "fname: " << fname << endl;
}
