#include <iostream>
#include <cstring>
#include <string>
int main()
{
	using namespace std;
	char word[5] = "?ate";
	string word_ = "?ate";
	for (char ch = 'a'; strcmp(word, "mate"); ch++) {	//	��strcmp����C-style���ַ������бȽ�
		word[0] = ch;
		cout << word << endl;
	}
	cout << endl;
	for (char ch = 'a'; word_ != "mate"; ch++) {	//	string����ֱ�������Ƚϣ�ֻ��Ҫ�Ƚϵ�����������������һ����string��Ϳ���
		word_[0] = ch;
		cout << word_ << endl;
	}

	while (cin.get() != 'q')
		;
	return 0;
}