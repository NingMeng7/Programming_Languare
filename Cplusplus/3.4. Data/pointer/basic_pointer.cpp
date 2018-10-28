#include <iostream>


int main()
{
	using namespace std;
	int updates = 6;
	int * p_updates;
	p_updates = &updates;
	cout << "Value: updates = " << updates << endl;
	cout << "*p_updates = " << *p_updates << endl;

	cout << "Address of updates: " << &updates << endl;
	cout << "p_updates = " << p_updates << endl;

	*p_updates += 1;
	cout << "Now, updates: " << updates << endl;

	while (cin.get() != 'q')
		;
	return 0;
}