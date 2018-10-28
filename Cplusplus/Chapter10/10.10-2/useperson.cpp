#include <iostream>
#include <string>
#include "person.h"

int main()
{
	using std::cout;
	using std::endl;
	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");
	one.show();
	cout << endl;
	one.Formalshow();
	two.show();
	cout << endl;
	two.Formalshow();
	three.show();
	cout << endl;
	three.Formalshow();
	return 0;
}
