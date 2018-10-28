#include <iostream>
#include "sale.h"

int main()
{
	using std::cin;
	using namespace SALES;
	Sales ar[2];
	double arr[4] = { 1,2,3,4};
	setSales(ar[0], arr, 3);
	setSales(ar[1]);
	showSales(ar[0]);
	showSales(ar[1]);
	while (cin.get() != 'q')
		;
	return 0;
}