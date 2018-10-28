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

	//	public methods
	Vector::Vector()
	{
		x = y = 0.0;
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
		}
		else if (form == POL) {
			x = n1 * cos(n2 / Rad_to_deg);
			y = n1 * sin(n2 / Rad_to_deg);
		}
		else {
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = 0.0;
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
		}
		else if (form = POL) {
			x = n1 * cos(n2 / Rad_to_deg);
			y = n1 * sin(n2 / Rad_to_deg);
		}
		else {
			cout << "Incorrect 3rd argument to Vector() -- ";
			cout << "vector set to 0\n";
			x = y = 0.0;
			mode = RECT;
		}
	}
	
	Vector::~Vector()	//	destructor
	{

	}
	
	double Vector::magval() const
	{
		return sqrt(x * x + y * y);
	}

	double Vector::angval() const
	{
		if (x == 0.0 && y == 0.0)
			return 0.0;
		else
			return atan2(y, x);
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
			os << "(m, a) = (" << v.magval() << ", " 
				<< v.angval() * Rad_to_deg << ")";
		}
		else
			os << "Vector/ object mode is invalid";
		return os;
	}
}
