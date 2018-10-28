/*************************************************************************
    > File Name: usemove.cpp
    > Author: JY.ZH
    > Mail: xw2016@mail.ustc.edu.cn 
    > Created Time: 2018年07月19日 星期四 15时23分07秒
 ************************************************************************/

#include<iostream>
#include"Move.h"

using namespace std;

int main()
{
	int i;
	Move test[3] = 
	{
		Move(1.0, 1.0),
		Move(2.0, 3.0),
		Move(10.0, -12.0)
	};
	
	cout << "Now I will display 3 move objects: " << endl;
	for(i=0; i<3; i++) {
		test[i].showmove();
	}

	cout << "Now I will add test[0] and test[1] to get a new move object: " << endl;
	Move newmove = test[0].add(test[1]);
	cout << "Newmove: " << endl;
	newmove.showmove();

	cout << "Now I will reset test[2]" << endl;
	test[2].reset();
	cout << "After resetting, newmove: " << endl;
	test[2].showmove();
	
	return 0;
}
