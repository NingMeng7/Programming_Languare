//  ��C-style�������ַ������ڳ�ʼ����ʱ������� '='
//  ����֮����и�ֵӦ��ʹ��strcpy(charr1,charr2)  strncpy(charr1,charr2,n) ��ิ��n���ַ���charr1�������Զ���'\0'

#include <iostream>
#include <cstring>

int main()
{
	using namespace std;
	char dog[8] = { 'f', 'a', 't', 'e', 's', 's', 'a', '\0' };  // '\0' is necessary
	char bird[11] = "Mr.cheeps";
	char fish[] = "Bubble";

	cout << "I'd give my right arm to be" " a great violinist.\n";

	cin >> bird;
	cout << bird;
	return 0;
}