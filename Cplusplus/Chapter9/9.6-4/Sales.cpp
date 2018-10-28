#include "sale.h"
#include <iostream>
namespace SALES {
	void setSales(Sales & s, const double ar[], int n)
	{
		if (n == 0)
			return;
		s.sales[0] = s.max = s.min = s.average = ar[0];
		for (int i = 1; i < n; i++) {
			s.sales[i] = ar[i];
			s.max = ar[i] > s.max ? ar[i] : s.max;
			s.min = ar[i] < s.min ? ar[i] : s.min;
			s.average += ar[i];
		}
		for (; n < QUARTERS; n++) {
			s.sales[n] = 0;
		}
		s.average /= n;

	}
	void setSales(Sales & s)
	{
		using namespace std;
		int i = 0;
		double max, min;
		cout << "Please enter the sales of #" << (i + 1) << " season: ";
		cin >> s.sales[i];
		s.average = max = min = s.sales[0];
		for (i = 1; i < QUARTERS; i++) {
			cout << "Please enter the sales of #" << (i + 1) << " season: ";
			cin >> s.sales[i];
			max = s.sales[i] > max ? s.sales[i] : max;
			min = s.sales[i] < min ? s.sales[i] : min;
			s.average += s.sales[i];
		}
		s.average /= QUARTERS;
		s.max = max;
		s.min = min;
	}
	void showSales(const Sales & s)
	{
		using namespace std;
		for (int i = 0; i < QUARTERS; i++) {
			cout << "Season #" << (i + 1) << " " << s.sales[i] << endl;
		}
		cout << "Average: " << s.average << endl;
		cout << "Max: " << s.max << endl;
		cout << "Min: " << s.min << endl;
	}
}