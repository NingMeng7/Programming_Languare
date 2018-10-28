//	This file provides the declaration of class Stock
#ifndef STOCK20_H_
#define STOCK20_H_

#include <string>

class Stock {
private:
	std::string company_;
	long shares_;
	double share_val_;
	double total_val_;
	void set_tot() { total_val_ = shares_ * share_val_; }	//	只有编写类的人可以使用它，并且这个函数将会是内联函数
public:
	//Stock(const std::string & company = "NO name", long shares = 0, double share_val = 0);	//	类构造函数
	Stock();	//	default constructor
	Stock(const std::string & company, long shares = 0, double share_val = 0);	//	类构造函数
	~Stock();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show() const;
	const Stock & topval(const Stock & s) const;
};

#endif
