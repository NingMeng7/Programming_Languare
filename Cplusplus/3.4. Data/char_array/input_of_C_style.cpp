/*
cin ͨ�� blank,\t,\n��ȷ���ַ�������λ��
*/
/*
cin.getline(arrname, N):����ȡN-1���ַ���arrname��
cin.getline()��ȡ���У�ͨ���س�������Ļ��з�ȷ�������β
RK: getline�Ὣ�������Ļ��з�ֱ�Ӷ���������룡getline���ȡ���з������ǻ�����滻Ϊ��
��һ���������N-1����
*/
/*
cin.get(arrname, N):����getline�����ǻ��з����������뻺������
cin.get(�޲���):��ȡ��һ���ַ��������ǻ��з�
�����з��İ취ʹ�����ǿ���ͨ�����������һ���ַ���ȷ��cin�ǵõ�N-1���ַ�ֹͣ���ǵõ�һ�ж�ֹͣ
*/
#include <iostream>
int main()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];
	cout << "When we use cin:" << endl;
	cout << "Please enter your name:\n";
	cin >> name;
	cout << "Please enter your favorite dessert:\n";
	cin >> dessert;
	cout << "I have some delicious " << dessert << " for you, " << name << endl; // Ya ya,��name����cin��׽Ya,����ya����������У���dessert��׽���� 

	cin.sync();	// ������뻺�� 

	cout << "When we use getline:" << endl;
	cout << "Please enter your name:\n";
	cin.getline(name, ArSize);
	cout << "Please enter your favorite dessert:\n";
	cin.getline(dessert, ArSize);
	cout << "I have some delicious " << dessert << " for you, " << name << endl;

	cin.sync();
	cout << "When we use get:" << endl;
	cout << "Please enter your name:\n";
	cin.get(name, ArSize);
	cout << "Please enter your favorite dessert:\n";
	cin.get(); // tricky one
	cin.get(dessert, ArSize);
	cout << "I have some delicious " << dessert << " for you, " << name << endl;

	return 0;
}