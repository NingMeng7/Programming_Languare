/*************************************************************************
    > File Name: mytime3.cpp
    > Author: JY.ZH
    > Mail: xw2016@mail.ustc.edu.cn 
    > Created Time: 2018年07月19日 星期四 20时54分06秒
 ************************************************************************/

#include<iostream>
#include "mytime3.h"

Time::Time()
{
	hours = minutes = 0;
}

Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void Time::AddHr(int h)
{
	hours += h;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

Time operator+(const Time & t, double x)
{
	Time result;
	long totalminutes = t.hours * 60 + t.minutes + x ;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}


Time operator+(double x, const Time & t)
{
	Time result;
	long totalminutes = t.hours * 60 + t.minutes + x ;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

Time operator+(const Time & t1, const Time & t2)
{
	Time result;
	result.minutes = (t1.minutes + t2.minutes) % 60;
	result.hours = t1.hours + t2.hours + (t1.minutes + t2.minutes) / 60;
	return result;
}

Time operator-(const Time & t1, const Time & t2)
{
	Time sub;
	int tot1, tot2;
	tot1 = t1.minutes + 60 * t1.hours;
	tot2 = t2.minutes + 60 * t2.hours;
	
	sub.minutes = (tot1 - tot2) % 60;
	sub.hours = (tot1 - tot2) / 60;

	return sub;
}

Time operator*(double mult, const Time & t)
{
	Time result;
	long totalminutes = t.hours * mult * 60 + t.minutes * mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

Time operator*(const Time & t, double mult)
{
	Time result;
	long totalminutes = t.hours * mult * 60 + t.minutes * mult;
	result.hours = totalminutes / 60;
	result.minutes = totalminutes % 60;
	return result;
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}


