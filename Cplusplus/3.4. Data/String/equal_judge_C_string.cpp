#include <iostream>
#include <cstring>
#include <string>
int main()
{
	using namespace std;
	char word[5] = "?ate";
	string word_ = "?ate";
	for (char ch = 'a'; strcmp(word, "mate"); ch++) {	//	用strcmp来对C-style的字符串进行比较
		word[0] = ch;
		cout << word << endl;
	}
	cout << endl;
	for (char ch = 'a'; word_ != "mate"; ch++) {	//	string可以直接用来比较，只需要比较的两个操作数，其中一个是string类就可以
		word_[0] = ch;
		cout << word_ << endl;
	}

	while (cin.get() != 'q')
		;
	return 0;
}