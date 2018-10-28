#include <iostream>
#include "account.h"

int main()
{
	using std::cout;
	using std::endl;
	BankAccount account;
	account = BankAccount("Tom", "1234567", 17500000);	
	account.show();
	
	cout << "Now I will deposit 2500000 into the account" << endl;
	account.deposit(2500000.0);
	account.show();
	
	cout << "Now I will withdraw 2500000 from the account" << endl;
	account.withdraw(2500000.0);
	account.show();
	
	return 0;
}

