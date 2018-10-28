#include <iostream>
#include <new>
#include <cstring>
struct chaff {
	char dross[20];
	int slag;
};
chaff arr[2];
void showchaff(const chaff &);
int main()
{
	chaff * p2 = new (arr) chaff[2];
	strcpy_s(p2[0].dross, "yaya");
	p2[0].slag = 0;
	strcpy_s(p2[1].dross, "woxihuanni");
	p2[1].slag = 1;
	showchaff(p2[0]);
	showchaff(p2[1]);
	while (std::cin.get() != 'q')
		;
	return 0;
}

void showchaff(const chaff & cha)
{
	using std::cout;
	using std::endl;
	cout << cha.dross << endl;
	cout << cha.slag << endl;
	cout << endl;
}