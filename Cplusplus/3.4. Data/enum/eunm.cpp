//  enum常常用来做符号常量声明，一般来说，只有声明中指出的那些值是有效的
//  事实上，枚举有range(取值范围)：upper: 2的幂次中比最大枚举值大的最小值-1,如max enum = 101=> 128-1 = 127
//  下限：如果最小值不小于0，则最小值是0，否则和upper方法一致，但是是负数+1
//  通过强制转换可以将符号常量之外的值赋给枚举值

#include <iostream>
#include <string>
#include <typeinfo>
enum spectrum { red, orange, yellow, green, blue, violet, indigo, ultraviolet };	//	0->7
enum sample1 { one = 1, two = 2, four = 4, eight = 8 };
enum sample2 { first, second = 100, third };	// third == 101, 每一项比前一项大一
enum sample3 { zero, null = 0, one_, uno = 1 };	// valid!! 可以创建多个值相同的枚举量


int main()
{
	using namespace std;
	spectrum color = blue;
	switch (color) {
	case red:
		cout << "red: " << color << endl;
		break;
	case orange:
		cout << "orange: " << color << endl;
		break;
	case blue:
		cout << "blue: " << color << endl;
		break;
	default:
		cout << "yellow: " << color << endl;	//偷懒了
	}
	while (cin.get() != 'q')
		;
	return 0;
}