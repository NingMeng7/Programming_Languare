//  enum�������������ų���������һ����˵��ֻ��������ָ������Щֵ����Ч��
//  ��ʵ�ϣ�ö����range(ȡֵ��Χ)��upper: 2���ݴ��б����ö��ֵ�����Сֵ-1,��max enum = 101=> 128-1 = 127
//  ���ޣ������Сֵ��С��0������Сֵ��0�������upper����һ�£������Ǹ���+1
//  ͨ��ǿ��ת�����Խ����ų���֮���ֵ����ö��ֵ

#include <iostream>
#include <string>
#include <typeinfo>
enum spectrum { red, orange, yellow, green, blue, violet, indigo, ultraviolet };	//	0->7
enum sample1 { one = 1, two = 2, four = 4, eight = 8 };
enum sample2 { first, second = 100, third };	// third == 101, ÿһ���ǰһ���һ
enum sample3 { zero, null = 0, one_, uno = 1 };	// valid!! ���Դ������ֵ��ͬ��ö����


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
		cout << "yellow: " << color << endl;	//͵����
	}
	while (cin.get() != 'q')
		;
	return 0;
}