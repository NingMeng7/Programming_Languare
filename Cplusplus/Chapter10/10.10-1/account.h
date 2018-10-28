#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <cstring>
class BankAccount
{
private:
	enum {Max = 30};
	char name[Max];
	char acctnum[Max];
	double balance;
public:
	BankAccount(const char * client, const char * num = "no name ", double bal = 0.0);
	BankAccount();
	void show(void) const;
	void deposit(double cash);
	void withdraw(double cash);
};

# endif
