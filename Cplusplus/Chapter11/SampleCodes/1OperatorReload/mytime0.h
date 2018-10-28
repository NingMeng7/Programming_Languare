/*************************************************************************
    > File Name: mytime0.h
    > Author: JY.ZH
    > Mail: xw2016@mail.ustc.edu.cn 
    > Created Time: 2018年07月19日 星期四 18时02分40秒
	> Description: Implement without operator overloading
 ************************************************************************/

#ifndef MYTIME0_H_
#define MYTIME0_H_

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
	Time Sum(const Time & t) const;
	void Show() const;
};

#endif 
