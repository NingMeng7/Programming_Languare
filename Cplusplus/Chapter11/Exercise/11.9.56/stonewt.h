/*************************************************************************
    > File Name: stonewt.h
    > Author: JY.ZH
    > Mail: xw2016@mail.ustc.edu.cn 
    > Created Time: 2018年07月20日 星期五 12时10分26秒
 ************************************************************************/

#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
private:
	enum {Lbs_per_stn = 14};	 //	pounds per stone
	enum Mode {STN, LBS};
	int stone;					 //	whole stones
	double pds_left;			 //	fractional pounds
	double pounds;				 //	entire weight in pounds
	Mode mode;
public:
	Stonewt(double lbs, Mode mode_);		 //	接受一个参数的构造函数可以用作隐式转换
	Stonewt(int stn, double lbs, Mode mode_);// constructor for stone, lbs
	Stonewt();					 //	default constructor
	~Stonewt();
//	conversion functions
	operator int() const;		 //	transformal function
	operator double() const;	 // 转换函数虽然没有声明返回类型，但是需要返回所需要的值
	friend std::ostream &
		operator<<(std::ostream & os, const Vector & v);
	Stonewt operator+(const Stonewt & t) const;
	Stonewt operator-(const Stonewt & t) const;
	bool operator>(const Stone & t) const;
	friend Stonewt operator+(double add, const Stone t) {return t + add;}
};
#endif
