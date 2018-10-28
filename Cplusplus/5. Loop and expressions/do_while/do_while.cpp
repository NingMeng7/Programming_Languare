#include <iostream>
int main()
{
	using namespace std;
	int n;

	cout << " Please enter a number in the range of 1-10 to find: ";
	cout << "my favorite number\n";
	do {
		cin >> n;
	} while (n != 7);
	cout << "Yes! My favorite number is 7!" << endl;
	while (cin.get() != 'q') {
		;
	}	
	return 0;
}