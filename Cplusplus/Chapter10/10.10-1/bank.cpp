#include <iostream>
#include "account.h"
#include <cstring>

BankAccount::BankAccount(const char * client, const char * num, double bal)
{
	strncpy(name, client, Max-1);
	strncpy(acctnum, num, Max-1);
	balance = bal;
}

BankAccount::BankAccount()
{
	strncpy(name, "no name", Max-1);
	strncpy(acctnum, "1234567", Max-1);
	balance = 0.0;
}

void BankAccount::show(void) const
{
	using std::cout;
	cout << "Name: " << name;
	cout << "\nAccount number: " << acctnum;
	cout << "\nBalance: " << balance << '\n';
}

void BankAccount::deposit(double cash)
{
	using std::cout;
	if(cash < 0) {
		cout << "Number of cash deposited can not be negative!"
			<< " Transaction is aborted.\n";
	}
	else
		balance += cash;
}

void BankAccount::withdraw(double cash)
{
	using std::cout;
	if(cash < 0) {
		cout << "Number of cash can not be negative!"
			<< " Transaction is aborted.\n";
	}
	else
		balance -= cash;
}
