#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void file_it(ostream & os, double fo, const double fe[], int n);  //  ostream是ofstream的父(基)类，基类引用可以接受派生类对象。
//  这是因为派生类也是基类??  from python I guess....
const int LIMIT = 5;
int main()
{
	ofstream fout;
	const char * fn = "ep-data.txt";
	fout.open(fn);
	if (!fout.is_open()) {
		cout << "Can't open " << fn << ".Bye!" << endl;
		exit(EXIT_FAILURE);
	}
	double objective;
	cout << "Please enter the focal length of your telescope objective in mm: ";
	cin >> objective;
	double eps[LIMIT];
	cout << "Please enter the focal lengths, in mm, of " << LIMIT << " eyepices: \n";
	for (int i = 0; i < LIMIT; i++) {
		cout << "Eyepiece #" << i + 1 << ": ";
		cin >> eps[i];
	}
	file_it(fout, objective, eps, LIMIT);	//	写入文件
	file_it(cout, objective, eps, LIMIT);	//	写到屏幕
	cout << "Done\n";
	while (cin.get() != 'q')
		;
	return 0;
}

void file_it(ostream & os, double fo, const double fe[], int n)
{
	ios_base::fmtflags initial;	//	储存开始的设置，ios_base::fmtflags 是储存这种设置的数据类型
	initial = os.setf(ios_base::fixed);	//	定点表示法	
					//	setf方法使得我们可以设置各种格式化状态
	os.precision(0);	//	指定显示多少位小数
	os << "Focal length of objective: " << fo << " mm\n";
	os.setf(ios::showpoint);
	os.precision(1);
	os.width(12);	//	指定显示的字段宽度，只对下一次输出有用，0表示恰好容纳所需要的空间
	os << "f.1. eyepiece";
	os.width(15);
	os << "magnification" << endl;
	for (int i = 0; i < n; i++) {
		os.width(12);
		os << fe[i];
		os.width(15);
		os << int(fo / fe[i] + 0.5) << endl;
	}
	os.setf(initial);	//	恢复格式化设置
}
