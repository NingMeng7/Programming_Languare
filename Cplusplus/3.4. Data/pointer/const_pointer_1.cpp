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
//	需要指出的是，如果在main中定义了一个 const数组 month
//	而函数 int sum(int arr[], int n);	调用时sum(month,12);是非法的，因为你将一个const指针赋给非const指针
//	const的数据无法赋给非const指针！否则这个const的数据会很可笑= =
//	这种技术只对基本类型有用，对于指针的指针不能这样做
void display(const string * sa, int n)
{
	for (int i = 0; i < n; i++)
		cout << i + 1 << ": " << sa[i] << endl;
}