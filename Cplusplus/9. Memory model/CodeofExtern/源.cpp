#include <iostream>

using namespace std;

double warming = 0.3;

void update(double dt);
void local();

int main()
{
	cout << "Global warming is " << warming << " degress.\n";
	update(0.1);
	cout << "Global warming is " << warming << " degress.\n";
	local();
	cout << "Global warming is " << warming << " degress.\n";
	while (cin.get() != 'q')
		;
	return 0;
}
