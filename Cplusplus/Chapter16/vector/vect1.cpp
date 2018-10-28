/*************************************************************************
    > File Name: vect1.cpp
    > Author: JY.ZH
    > Mail: xw2016@mail.ustc.edu.cn 
    > Created Time: 2018年07月29日 星期日 15时33分54秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

const int N = 5;

int main()
{
	using std::vector;
	using std::string;
	using std::cin;
	using std::cout;

	vector <int> ratings(N);
	vector <string> titles(N);
	
	cout << "You will do exactly as told. You will enter\n"
		<< N << " book titles and your ratings (0-10).\n";

	int i;
	for(i = 0; i < N; i++) {
		cout << "PLease enter title #" << i + 1 << ": ";
		getline(cin, titles[i]);
		cout << "PLease enter your rating (0-10): ";
		cin >> ratings[i];
		cin.get();
	}

	cout << "Thank you. You enter the following:\n" << "Rating\tBook\n";
	
	for(i = 0; i < N; i++) {
		cout << ratings[i] << "\t" << titles[i] << "\n";

	}

	return 0;
	
}
