#include<iostream>
#include <string>
int main()
{
	using namespace std;
	string str1, str2, str3;
	cout << "Please enter the string: ";
	cin >> str1;
	cout << str1 << endl;

	cin.get();  // ����cin����������еĻ��з�
	getline(cin, str2);
	cout << str2 << endl;

	//get(cin, str3); //  get�ƺ����а�
	//cout << str3 << endl;
	return 0;

}