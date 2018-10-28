// 编写特定的函数来对特定数据进行处理，使得程序可靠性更高，修改调试更加方便
// 将存储属性和对应操作结合起来:OOP思想 
// 在main函数中和fill_array函数中，分别展示了遇到bad input的时候，是直接结束还是等待用户输入一个good input的技巧
#include <iostream>
const int Max = 5;
int fill_array(double ar[], int limit);
void show_array(const double ar[], int n);
void revalue(double r, double ar[], int n);

int main()
{
	using namespace std;
	double properties[Max];
	
	int size = fill_array(properties, Max);
	show_array(properties, size);
	if (size > 0) {
		cout << "Please enter revaluation factor: ";
		double factor;
		while (!(cin >> factor)) {	// cin expect an input of number, if not, cin>>factor == Flase makes the cycle continue
			cin.clear(); 	// Bad input会使得后来的输入被封锁，需要clear一下才能继续输入 
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; Please enter a number: ";
		}
	revalue(factor, properties, size);
	show_array(properties, size);
	}
	cout << "Done!" << endl;
	cin.get();
	cin.get();
	return 0;
}


int fill_array(double ar[], int limit)
{
	using namespace std;
	double temp;
	int i;
	for (i = 0; i < limit; i++) {
		cout << "Please enter value #" << (i + 1) << ": ";
		cin >> temp;
		if (!cin) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (temp < 0)
			break;
		ar[i] = temp;	
	}
	return i;
}


void show_array(const double ar[], int n)
{
	using namespace std;
	for (int i = 0; i < n; i++) {
		cout << "Property #" << (i + 1) << ": $";
		cout << ar[i] << endl;
	}
}


void revalue(double r, double ar[], int n)
{
	for (int i = 0; i < n; i++) {
		ar[i] *= r;
	}
}


