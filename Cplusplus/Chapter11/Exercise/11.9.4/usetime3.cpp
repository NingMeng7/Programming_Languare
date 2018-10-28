/*************************************************************************
    > File Name: usetime3.cpp
    > Author: JY.ZH
    > Mail: xw2016@mail.ustc.edu.cn 
    > Created Time: 2018年07月19日 星期四 21时02分40秒
 ************************************************************************/

#include <iostream>
#include "mytime3.h"

int main()
{
	using std::cout;
	using std::endl;

	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;

	cout << "Aida and Tosca:" << endl;
	cout << aida << "; " << tosca << endl;
	
	temp = aida + tosca;
	
	cout << "Aida + Tosca: " << temp << endl;
	temp = aida * 1.17;
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10.0 * Tosca: " << 10.0 * tosca << endl;

	return 0;
}
