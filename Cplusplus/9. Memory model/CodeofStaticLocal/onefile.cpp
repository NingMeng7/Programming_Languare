#include <iostream>
const int ArSize = 10;

void strcount(const char * str);
int main()
{
	using namespace std;
	char input[ArSize];
	char next;

	cout << "Please enter a line:\n";
	cin.get(input, ArSize);
	while (cin) {
		cin.get(next);
		while (next != '\n')
			cin.get(next);
		strcount(input);
		cout << "Please enter line (empty line to quit): " << endl;
		cin.get(input, ArSize);	//	cin.get把enter留在输入队列里，可以用cin来判断是否真正输入了数据
	}
	cout << "Bye!" << endl;
	return 0;
}

void strcount(const char * str)
{
	using namespace std;
	static int total = 0;
	int count = 0;
	
	cout << "\"" << str << "\" contains ";
	while (*str++)
		count++;
	total += count;
	cout << count << " characters" << endl;
	cout << total << " characters" << endl;
}
