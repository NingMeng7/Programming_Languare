//	This file provides the details of implements of member functions
#include <iostream>
#include "Stock20.h"

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

void Stock::show() const	//	promise not to change invoking object
{								//	similar to the const reference 
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

Stock::Stock()
{
	std::cout << "default cosntructor called \n";
	company_ = "no name";
	shares_ = 0;
	share_val_ = 0;
	total_val_ = 0;
}

Stock::~Stock()
{
	std::cout << "Bye, " << company_ << "!\n";
}

/*	Description: This function demostrates the way we use pointer this
 *	Args: const Stock & s. We visit object s explicitly and promise not to change it
 *  return: Reference of the object with higher total_val
 */
const Stock & Stock::topval(const Stock & s) const	//	最后这个const让我们无法(通过this)修改调用这个方法的对象
{
	if (s.total_val_ > total_val_)
		return s;
	else
		return *this;
}


