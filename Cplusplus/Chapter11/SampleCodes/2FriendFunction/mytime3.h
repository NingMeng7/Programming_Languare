/*************************************************************************
    > File Name: mytime3.h
    > Author: JY.ZH
    > Mail: xw2016@mail.ustc.edu.cn 
    > Created Time: 2018年07月19日 星期四 20时48分19秒
 ************************************************************************/

#ifndef MYTIME3_H_
#define MYTIME3_H_
#include <iostream>

class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	Time operator+(const Time & t) const;
	Time operator-(const Time & t) const;
	Time operator*(double n) const;
	friend Time operator*(double m, const Time & t)
		{return t * m;}	//	用友元函数来逆转参数顺序
	friend std::ostream & operator<<(std::ostream & os, const Time & t);
};

#endif
