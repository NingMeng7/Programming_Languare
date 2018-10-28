#include <iostream>
const int ArSize = 6;
int main()
{
	using namespace std;
	float naaq[ArSize];
	cout << "Please enter the NAAQs (New Age Awareness Quotients) "
		<< "of\nyour neighbors. Program terminates when you make\n"
		<< ArSize << " entries " << "or enter a negative value.\n";

	int i = 0;
	float temp;
	cout << "First value: ";
	cin >> temp;

	while (i < ArSize && temp >= 0) {	//	检测i是否越界，以及数据是否合法
		naaq[i] = temp;
		++i;
		if (i < ArSize) {
			cout << "Next value: ";
			cin >> temp;
		}
	}
	if (i == 0) {
		cout << "No data--bye\n";
	}
	else {
		cout << "Please enter your NAAQ: ";
		float you;
		cin >> you;
		int count = 0;
		for (int j = 0; j < i; j++)
			if (naaq[j] > you)
				++count;
		cout << count;
		cout << " of your neighbors have greater awareness of "
			<< "the New Age that you do.\n";
	}


	while (std::cin.get() != 'q')
		;
	return 0;
}