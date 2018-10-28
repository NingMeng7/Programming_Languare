/*************************************************************************
    > File Name: vector.h
    > Author: JY.ZH
    > Mail: xw2016@mail.ustc.edu.cn 
    > Created Time: 2018年07月19日 星期四 22时26分13秒
	> Description: This file incldues the definition of class and Namespace vector
 ************************************************************************/

#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>

namespace VECTOR
{
	class Vector
	{
	public:	//	Two ways to let class include constant, static const or enum
		enum Mode{RECT, POL};	//	RECT for rectrangular, POL for Polar modes
	private:
		double x;
		double y;
		Mode mode;
	public:
		Vector();
		Vector(double n1, double n2, Mode form = RECT);
		void reset(double n1, double n2, Mode form = RECT);
		~Vector();
		double xval() const {return x;}
		double yval() const {return y;}
		double magval() const;
		double angval() const;
		void polar_mode();	//	set mode to POL
		void rect_mode();	//	set mode to RECT
	//	operator overloading
		Vector operator+(const Vector & b) const;
		Vector operator-(const Vector & b) const;
		Vector operator-() const;	//	特征标不同
		Vector operator*(double n) const;
	//	friends
		friend Vector operator*(double n, const Vector & a);
		friend std::ostream & 
			operator<<(std::ostream & os, const Vector & v);
	};	
}

/*
 *	1.	使用友元函数,在类原型中前缀要加friend关键字，但是在之后的定义中不加.
 *	2.	友元函数不是成员函数,不能使用成员运算符来调用,同时给出的定义的时候不需要使用 Classname::的限定符
 *	3.	友元函数具有和成员函数相同的访问权限
 */
#endif
