#include <iostream>
#include <string>
const int limit = 10;
int main()
{
	using namespace std;
	char temp;

	for (int i = 0; i < limit; i++) {	//  for ���������ѭ��
		cout << i << endl;
	}
	//cout << i;	invalid,��forѭ���������ı���i�뿪forѭ������ʧ
	cout << endl;

	for (int i = 0; i < limit; i += 2) {	//	����
		cout << i << endl;
	}

	if (limit == 10) {
		int y = 100;
		cout << "The value of y: " << y << endl;	//	�����ڲ��ı���y���������ⲿ����y(����еĻ�)
	}
	//cout << y;	invalid,�ڸ��������������ı���y���뿪�������ʧ
	cout << endl;

	string word = "abcdefghijk";
	cout << "Before reverse:" << endl;
	cout << word << endl;
	for (int j = 0, i = word.size() - 1; j < i; ++j, --i) {
		temp = word[i];
		word[i] = word[j];
		word[j] = temp;
	}
	cout << "After reverse: " << endl;
	cout << word << endl;

	while (cin.get() != 'q')
		;
	return 0;
}