#include <iostream>
#include <string>
const int ArSize = 10;
using namespace std;
void strcount(const string input);
int main()
{
	string input;

	cout << "Please enter a line:\n";
	getline(cin, input);
	while (input != "") {
		strcount(input);
		cout << "Please enter line (empty line to quit): " << endl;
		getline(cin, input);	
	}
	cout << "Bye!" << endl;
	return 0;
}

void strcount(const string input)
{
	using namespace std;
	static int total = 0;
	int count = input.length();

	cout << "\"" << input << "\" contains ";
	total += count;
	cout << count << " characters" << endl;
	cout << total << " characters" << endl;
}
