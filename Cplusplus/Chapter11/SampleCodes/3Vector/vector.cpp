/*************************************************************************
    > File Name: vector.cpp
    > Author: JY.ZH
    > Mail: xw2016@mail.ustc.edu.cn 
    > Created Time: 2018年07月19日 星期四 22时39分29秒
 ************************************************************************/

#include <cmath>
#include "vector.h"
#include <iostream>

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR	//	Remark: namespace is open, we can add details here
{
	//	compute degrees in one radian
	const double Rad_to_deg = 45.0 / atan(1.0);	//	名称空间可以放常量

	//	private methods
	//	The following 4 functions used to set values automatically
	void Vector::set_mag()
	{
		mag = sqrt(x * x + y * y);
	}

	void Vector::set_ang()
	{
		if (x == 0.0 && y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y, x);
	}

	//	set x from polar coordinate
	void Vector::set_x()
	{
		x = mag * cos(ang);
	}
	
	//	set y from polar coordinate
	void Vector::set_y()
	{
		y = mag * sin(ang);
	}

	//	public methods
	Vector::Vector()
	{
		x = y = mag = ang = 0.0;
		mode = RECT;
	}
	
	//	construct vector from rectangular coordinates if form is r
	//	(the default) or else from polar coordinates if form is p
	Vector::Vector(double n1, double n2, Mode form)
	{
		mode = form;
		if (form == RECT) {
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form == POL) {
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else {
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}
	
	//	reset Vector from rectangular coordinates if form is RECT(the default) 
	//	or else from polar coordinates if form is POL
	void Vector::reset(double n1, double n2, Mode form)
	{
		mode = form;
		if (form = RECT) {
			x = n1;
			y = n2;
			set_mag();
			set_ang();
		}
		else if (form = POL) {
			mag = n1;
			ang = n2 / Rad_to_deg;
			set_x();
			set_y();
		}
		else {
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = mag = ang = 0.0;
			mode = RECT;
		}
	}
	
	Vector::~Vector()	//	destructor
	{

	}
	
	void Vector::polar_mode()	//	set to polar mode
	{
		mode = POL;
	}

	void Vector::rect_mode()	//	set to rectangular mode
	{
		mode = RECT;
	}

	//	operator overloading
	//	Implement operator overloading by constructor! It's easy and safe!
	//	add two Vectors
	Vector Vector::operator+(const Vector & b) const
	{
		return Vector(x + b.x, y + b.y);
	}

	//	subtract Vector from a
	Vector Vector::operator-(const Vector & b) const
	{
		return Vector(x - b.x, y - b.y);
	}

	//	reverse sign of Vector
	Vector Vector::operator-() const
	{
		return Vector(-x, -y);
	}

	//	multiply vector by n
	Vector Vector::operator*(double n) const
	{
		return Vector(n * x, n * y);
	}

	//	friend methods
	//	multiply n by vector a
	Vector operator*(double n, const Vector & a)
	{
		return a * n;
	}

	//	display rectangular coordinates if mode is RECT,
	//	else display polora coordinates if mode if POL
	std::ostream & operator<<(std::ostream & os, const Vector & v)
	{
		if (v.mode == Vector::RECT) {
			os << "(x, y) = (" << v.x << ", "<< v.y <<")";
		}
		else if (v.mode == Vector::POL) {	//	VECTOR::Vector::POL, 这里在名称空间中可以省掉VECTOR,友元函数并不在类作用域里，所以需要使用Vector::! 但是它可以访问私有成员!
			os << "(m, a) = (" << v.mag << ", "	//	友元函数以类为参数，通过成员运算符访问其中的成员 
				<< v.ang * Rad_to_deg << ")";
		}
		else
			os << "Vector/ object mode is invalid";
		return os;
	}
}
