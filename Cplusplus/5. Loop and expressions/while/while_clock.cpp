#include <iostream>
#include <ctime>
int main()
{
	using namespace std;
	cout << "Please enter the delay time in the unit of second: ";
	double secs;
	cin >> secs;
	clock_t delay = secs * CLOCKS_PER_SEC;

	cout << "Now,we start!" << endl;
	clock_t start = clock();
	while (clock() - start < delay) {
		;
	}
	cout << "Done!\a" << endl;
	while (cin.get() != 'q') {
		;
	}
	return 0;
}