#include <iostream>
int main()
{
	using namespace std;
	char ch;
	int count = 0;
	cout << "Please enter the text and quit with #: " << endl;
	cin >> ch;
	while (ch != '#') {	//  blank,�Ʊ��,�س������ᱻ����
		cout << ch;
		++count;
		cin >> ch;
	}
	cout << endl << count << " characters read\n";

	cin.ignore(1024, '\n');	//	����һ�γ���Ľ�β�س�Ӱ������

	count = 0;
	cout << "Please enter the text and quit with #: " << endl;
	cin.get(ch);	//	get���Եõ��������һ���ַ��������ո�
	while (ch != '#') {
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << " characters read\n";


	cin.ignore(1024, '\n');	//	����һ�γ���Ľ�β�س�Ӱ������


	count = 0;
	cout << "Please enter the text and quit with EOF: " << endl;
	cin.get(ch);
	while (cin.fail() == false) {	//  quit with EOF(Ctrl+Z)
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << " characters read \n";


	cin.ignore(1024, '\n');	//	����һ�γ���Ľ�β�س�Ӱ������
	cin.clear();

	count = 0;
	cout << "Please enter the text and quit with EOF: " << endl;
	while (cin.get(ch)) {	//	cin.get()������ʽ��ֵ����������Ǹ��ַ�
		cout << ch;	//	cin������Ϊboolֵ�������һ�ζ�ȡ�ɹ���cin==true,��cin.get(char)�ķ���ֵ��cin����˿��Լ򻯳���������
		++count;
	}
	cout << endl << count << " characters read \n";
	cin.clear();
	while (cin.get() != 'q') {
		;
	}
	return 0;
}