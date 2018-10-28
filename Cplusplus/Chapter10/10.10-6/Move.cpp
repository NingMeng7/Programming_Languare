/*************************************************************************
    > File Name: Mov.cpp
    > Author: JY.ZH
    > Mail: xw2016@mail.ustc.edu.cn 
    > Created Time: 2018年07月19日 星期四 15时11分21秒
 ************************************************************************/

#include <iostream>
#include "Move.h"

Move::Move(double a, double b)	//	没有返回类型，注意细节实现别把默认参数写上
{
	x = a;
	y = b;
}

void Move::showmove() const
{
	using std::cout;
	using std::endl;

	cout << "(x, y) = (" << x << ", " << y << ")" << endl;
}

Move Move::add(const Move & m) const
{
	double new_x, new_y;

	new_x = m.x + this->x;
	new_y = m.y + this->y;

	Move newmove = Move(new_x, new_y);
	
	return newmove;
}

void Move::reset(double a, double b)
{
	x = a;
	y = b;
}
