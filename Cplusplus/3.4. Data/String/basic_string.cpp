#include <iostream>
#include <string> // make string class available
int main()
{
	using namespace std;
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";  // C-����ַ�����ʼ��

	cout << "Please enter a kind of feline: ";
	cin >> charr1;
	cout << "Please enter another kind of feline: ";
	cin >> str1;  //  string����cin����������
	cout << "Here are some felines:" << endl;
	cout << charr1 << " " << charr2 << " "
		<< str1 << " " << str2 << endl;
	cout << "The third letter in " << charr2 << " is "
		<< charr2[2] << endl;
	cout << "The third letter in " << str2 << " is "
		<< str2[2] << endl;  //  string���������

							 //  string�����ʹ��string���Խ��и�ֵ��ƴ�Ӻ͸���
							 //  ��ӦC-style�ַ����е�strcpy(charr1, charr2): copy charr2 to charr1     
							 //  strcat(charr1, " juice") add juice to end of charr1
							 //  strlen(charr1)  obtain length of charr1

	str1 = str2;
	string str3;
	str3 = str1 + str2;
	cout << str3 << endl;
	//cout << str1[0] + str2[2] << endl;  ����֮���Ԫ�ؾͱ��char������string����

	cout << "The length of str3 is: " << str3.size() << endl; //  size������'\0'

	str1 += '\0';
	str1 += "abc";
	cout << str1 << endl; //  string����'\0'Ϊ������־����˿��԰���'\0'
	return 0;

}