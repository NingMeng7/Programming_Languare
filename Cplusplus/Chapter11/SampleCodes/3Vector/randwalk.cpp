/*************************************************************************
    > File Name: randwalk.cpp
    > Author: JY.ZH
    > Mail: xw2016@mail.ustc.edu.cn 
    > Created Time: 2018年07月20日 星期五 00时04分22秒
 ************************************************************************/

#include <iostream>
#include <fstream>		//	output the location to a file
#include <cstdlib>		//	rand(), srand() prototypes
#include <ctime>		//	time()	prototypes
#include "vector.h"

int main()
{
	using namespace std;
	using VECTOR::Vector;	//	make class Vector available
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	
	ofstream fout;
	fout.open("Thewalk.txt");

	cout << "Enter target distance (q to quit): ";
	while (cin >> target) {
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;

		while (result.magval() < target) {
			direction = rand() % 360;	//	random direction
			step.reset(dstep, direction, Vector::POL);
			result = result + step;	//	vector addition
			steps++;
			fout << result << endl;
		}

		cout << "After " << steps << " steps, the subject "
			"has the following location:\n";
		cout << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	return 0;
}
