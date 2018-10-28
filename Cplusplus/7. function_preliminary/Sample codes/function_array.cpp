#include <iostream>
const int Max = 5;
int fill_array(double ar[], int limit);
void show_array(const double ar[], int n);	//  const不说明ar数组内是常量，而是说明在这个函数内，ar中的数据是只读的，不能修改，否则报错
void revalue(double r, double ar[], int n);

int main()
{
	using namespace std;
	double properties[Max];
	double factor;

	int size = fill_array(properties, Max);
	show_array(properties, size);	//	请注意，尽管数组名和指针在很多情况是一致的，但是在子函数中，properties被解释为指针
									//	sizeof将无法从指针得到数组的长度，因此必须显示传递size
	if (size > 0) {
		cout << "Enter revaluation factor: ";
		while (!(cin >> factor)) {
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; please enter a number:";
		}
		revalue(factor, properties, size);
		show_array(properties, size);
	}
	cout << "Done!\n";

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
		cout << "Please enter the value #" << i + 1 << ": ";
		cin >> temp;
		if (!cin) {	//	没有输入
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input! input process terminated!\n";
			break;
		}
		else if (temp < 0) {	//	输入小于0
			break;
		}
		else
			ar[i] = temp;
	}
	return i;
}

void show_array(const double ar[], int n)
{
	using namespace std;
	for (int i = 0; i < n; i++) {
		cout << "Property #" << i + 1 << ": $";
		cout << ar[i] << endl;
	}
}

void revalue(double r, double ar[], int n)
{
	for (int i = 0; i < n; i++) {
		ar[i] *= r;
	}
}