#include <iostream>
#include <string>
const int SIZE = 5;
using namespace std;
void display(const string * sa, int n);
int main()
{
	string list[SIZE];
	cout << "Please enter your " << SIZE << " favorite astronomical sights:\n";
	for (int i = 0; i < SIZE; i++) {
		cout << i + 1 << ": ";
		getline(cin, list[i]);
	}
	cout << "Your list:\n";
	display(list, SIZE);
	return 0;
}
//	��Ҫָ�����ǣ������main�ж�����һ�� const���� month
//	������ int sum(int arr[], int n);	����ʱsum(month,12);�ǷǷ��ģ���Ϊ�㽫һ��constָ�븳����constָ��
//	const�������޷�������constָ�룡�������const�����ݻ�ܿ�Ц= =
//	���ּ���ֻ�Ի����������ã�����ָ���ָ�벻��������
void display(const string * sa, int n)
{
	for (int i = 0; i < n; i++)
		cout << i + 1 << ": " << sa[i] << endl;
}