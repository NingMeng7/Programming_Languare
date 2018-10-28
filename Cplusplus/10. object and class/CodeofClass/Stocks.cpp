//	This file shows two ways to create new object

#include <iostream>
#include "stock.h"

int main()
{
	{
		using std::cout;
		using std::endl;
		
		cout << "Using constructor to create new object:\n";
		Stock stock1("NanoSmart", 12, 20.0);
		stock1.show();
		
		Stock stock2 = Stock("Boffo Objects", 2, 2.0);	
		stock2.show();

		cout << "Assigning stock1 to stock2:\n";
		stock2 = stock1;	//	��֮���ֱ�Ӹ�ֵ�ǺϷ���
		cout << "Listing stock1 and stock2: " << endl;
		stock1.show();
		stock2.show();

		cout << "Using a constructor to reset an object \n";
		stock1 = Stock("Nifty Foods", 10, 50.0);	//	�����н�����Կ������������������һ����ʱ����
		cout << "Revised stock1:\n";
		stock1.show();
		cout << "Done\n";
	}	//	Code segment set on purpose for the demo of destructor
	//	destructor ���õ�˳����ʵ��Ӧ���Զ�������ͨ��ջ���������ʵ, ���Stock1�Ƚ����

	while (std::cin.get() != 'q')
		;
	return 0;
}
