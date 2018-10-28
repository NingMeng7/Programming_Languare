#include <iostream>
struct inflatable
{
	float volume;
};
int main()
{
	using namespace std;
	inflatable s1, s2, s3;
	s1.volume = 1998;
	cout << "s1.volume: " << s1.volume << endl;

	inflatable * pa = &s2;
	pa->volume = 1999;
	cout << "pa->volume: " << pa->volume << endl;

	inflatable tri[3];
	tri[0].volume = 2003;
	cout << "tri[0].volume: " << tri[0].volume << endl;

	const inflatable * arp[3] = { &s1, &s2, &s3 };	//	结构体指针的数组
	cout << "arp[1]->volume: " << arp[1]->volume << endl;

	const inflatable ** ppa = arp;	//	二维指针，指针的指针
	auto ppb = arp;
	cout << "(*ppa)->volume: " << (*ppa)->volume << endl;
	cout << "(*(ppb+1))->volume: " << (*(ppb + 1))->volume << endl;

	while (cin.get() != 'q')
		;
	return 0;
}