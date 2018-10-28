#include "iostream"

int main()
{
	using namespace std;
	char ch;
	int count = 0;
	cout << "Please enter the text and quit with EOF: " << endl;
	while (cin.get(ch)) {
		cout << ch;
		++count;
	}
	cout << count << " charaters has been rean\n";

	cin.ignore(1024, '\n');
	cin.clear();

	count = 0;
	cout << "Please enter the text and quit with EOF:  " << endl;
	while ((ch = cin.get()) != EOF) {
		cout << ch;
		++count;
	}
	cout << count << " characters has been read\n";

	cin.clear();
	return 0;
}
