//	����һ�����������ղ�ͬ���̵��ַ�������ָ����ָ������
//	ָ����ṹ�����ʹ�ã��ȿ���ֱ������һ���ṹ���ָ�룬Ȼ��ͨ��new�����ָ������ڴ�ռ�������һ���ṹ��
//	Ҳ��������һ���ṹ�壬Ȼ������һ��ָ��ָ������ṹ��
#include <iostream>
#include <cstring>
#define MaxLength 80
struct inflatable
{
	char* name;
	float volume;
	double price;
};
void show(inflatable * ps)
{
	using namespace std;
	cout << "name: " << ps->name << endl;
	cout << "volume: " << ps->volume << endl;
	cout << "price: " << ps->price << endl;
}
char * getname()
{
	using namespace std;
	char temp[MaxLength];
	cout << "Please enter the name: ";
	cin.get(temp, MaxLength);
	char* pn = new char[strlen(temp) + 1];
	strcpy_s(pn, strlen(temp) + 1, temp);
	return pn;
}
int main()
{
	using namespace std;
	inflatable * ps = new inflatable;
	ps->name = getname();
	cout << "Please enter the volume in cuic feet: ";
	cin >> ps->volume;
	cout << "Please enter the price: ";
	cin >> ps->price;
	show(ps);
	delete[] ps->name;	// ע�⣬���д����new��deleteд��������������Ӧ���ǵ��ͷ��ڴ�
	delete ps;

	while (cin.get() != 'q')
		;
	return 0;
}