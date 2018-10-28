//	This file provides the declaration of class Stock
#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>

class Stock {
private:
	std::string company_;
	long shares_;
	double share_val_;
	double total_val_;
	void set_tot() { total_val_ = shares_ * share_val_; }	//	�͵ض��壬ֻ�б�д����˿���ʹ�������������������������������
public:
	Stock(const std::string & company, long shares = 0, double share_val = 0);	//	�๹�캯��
	//	Stock();	//	default constructor
	~Stock();
	void acquire(const std::string & co, long n, double pr); // ��ͷ�ļ���ֻ����ԭ�ͣ���ʵ���ļ�����
	void buy(long num, double price);	// ϸ��
	void sell(long num, double price);
	void update(double price);
	void show() const;
};
#endif
