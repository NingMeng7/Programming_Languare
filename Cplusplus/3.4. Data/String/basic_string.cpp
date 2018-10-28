#include <iostream>
#include <string> // make string class available
int main()
{
	using namespace std;
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";  // C-风格字符串初始化

	cout << "Please enter a kind of feline: ";
	cin >> charr1;
	cout << "Please enter another kind of feline: ";
	cin >> str1;  //  string类用cin来进行输入
	cout << "Here are some felines:" << endl;
	cout << charr1 << " " << charr2 << " "
		<< str1 << " " << str2 << endl;
	cout << "The third letter in " << charr2 << " is "
		<< charr2[2] << endl;
	cout << "The third letter in " << str2 << " is "
		<< str2[2] << endl;  //  string类进行索引

							 //  string类设计使得string可以进行赋值，拼接和附加
							 //  对应C-style字符串中的strcpy(charr1, charr2): copy charr2 to charr1     
							 //  strcat(charr1, " juice") add juice to end of charr1
							 //  strlen(charr1)  obtain length of charr1

	str1 = str2;
	string str3;
	str3 = str1 + str2;
	cout << str3 << endl;
	//cout << str1[0] + str2[2] << endl;  索引之后的元素就变成char而不是string类了

	cout << "The length of str3 is: " << str3.size() << endl; //  size不计算'\0'

	str1 += '\0';
	str1 += "abc";
	cout << str1 << endl; //  string不以'\0'为结束标志，因此可以包含'\0'
	return 0;

}