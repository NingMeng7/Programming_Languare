//	This file provides the details of implements of member functions
#include <iostream>
#include "stock.h"
// ������Ķ�������ͷ�ļ�stock.h


void Stock::acquire(const std::string & co, long n, double pr)	//	�ڶ����ʱ��Ҫͨ������������������ָ�����������ڵ���
{
	company_ = co;	//	��Ա�������Ե������ private ����
	if (n < 0) {
		std::cout << "Number of shares can't be negative;"
			<< company_ << " shares set to 0.\n";
		shares_ = 0;
	}
	else
		shares_ = n;
	share_val_ = pr;
	set_tot();
}

void Stock::buy(long num, double price)
{
	if (num < 0) {
		std::cout << "Number of shares purchased can't be negative. "
			<< company_ << " Transaction is aborted.\n";
	}
	else {
		shares_ += num;
		share_val_ = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;
	if (num < 0) {
		cout << "Number of shares sold can't be negative. "
			<< company_ << " Transaction is aborted.\n";
	}
	else if (num > shares_) {
		cout << "You can't sell more than you have!"
			<< company_ << " Transaction is aborted.\n";
	}
	else {
		shares_ -= num;
		share_val_ = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val_ = price;
	set_tot();
}

void Stock::show() const
{
	using std::cout;
	using std::ios_base;
	ios_base::fmtflags orig =
		cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);
	cout << "Company: " << company_
		<< "	Shares: " << shares_ << '\n'
		<< "	Share Price: $" << share_val_;

	cout.precision(2);
		
	cout << "	Total Worth: $" << total_val_ << '\n';
	cout.setf(orig, ios_base::floatfield);
	cout.precision(prec);
}

Stock::Stock(const std::string & company, long shares, double share_val)
{
	company_ = company;
	if (shares < 0) {
		std::cerr << "Number of shares can't be negative; "
			<< company << " shares set to 0.\n";
		shares_ = 0;
	}
	else
		shares_ = shares;
	share_val_ = share_val;
	set_tot();
}

/*
Stock::Stock()
{
	std::cout << "default cosntructor called \n";
	company = "no name";
	shares_ = 0;
	shares_val_ = 0;
	total_val_ = 0;
{
*/

Stock::~Stock()
{
	std::cout << "Bye, " << company_ << "!\n";
}
