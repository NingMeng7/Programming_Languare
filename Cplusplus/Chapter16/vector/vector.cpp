/*************************************************************************
    > File Name: vector.cpp
    > Author: JY.ZH
    > Mail: xw2016@mail.ustc.edu.cn 
    > Created Time: 2018年07月29日 星期日 14时44分35秒
 ************************************************************************/

#include<iostream>
#include <vector>

using namespace std;


int main()
{	
	//	1. initialize of vector
	vector <int> v0;
	vector <int> v1(5, 0);

	//	2. make a copy
	vector <int> v2(v1.begin(), v1.end());	//	past-the-end　v1.end()返回的iterator指向的是最后一个元素后一个元素
	vector <int> v3(v2);
	
	//	3. cast an array to vector
	int a[5] = {0, 1, 2, 3, 4};
	vector <int> v4(a, *(&a+1));

	//	4. get lengh and access element
	cout << "The size of v4 is : " << v4.size() << endl;
	cout << "The first element of v4 is: " << v4[0] << endl;

	//	5. Iteration of vector
	cout << "Version1 to display v4: " << endl;	//	vector acts like an array
	for (int i = 0; i < v4.size(); ++i) {
		cout << " " << v4[i];
	}
	cout << endl;

	
	cout << "Version2 to display v4: " << endl;	//	范围for使得我们可以对容器内容修改(与for_each相比)
/*	for (int & item : v4) {
		cout << " " << item;
	}
	cout << endl;
*/
	for (auto & item : v4)
		cout << " " << item;
	cout << endl;


	cout << "Version3 to display v4: " << endl;
	for (auto item = v4.begin(); item != v4.end(); ++item) {	//	by iterator
		cout << " " << *item;
	}
	cout << endl;
	
	//	6.modify element
	v4[0] = 5;

	//	7.sort
//	qsort(v4.begin(), v4.end());

	//	8.add new element at the end of the vector
	v4.push_back(10);

	//	9.delete the latest element
	v4.pop_back();
	
	return 0;
}

