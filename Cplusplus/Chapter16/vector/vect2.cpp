/*************************************************************************
    > File Name: vect2.cpp
    > Author: JY.ZH
    > Mail: xw2016@mail.ustc.edu.cn 
    > Created Time: 2018年07月29日 星期日 16时12分54秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>

struct Review {
	std::string title;
	int rating;
};
bool FillReview(Review & rr);
void ShowReview(const Review & rr);

int main()
{
	using std::cout;
	using std::vector;
	vector <Review> books;
	Review temp;

	while (FillReview(temp)) {
		books.push_back(temp);
	}
	
	int num = books.size();
	if (num > 0) {
		
		cout << "Thank you. You entered the following:\n"
				<< "Rating\tBook\n";
		for (int i = 0; i < num; ++i) 
			ShowReview(books[i]);
		
		cout << "Repreising: \n" << "Rating\tBook\n";
		vector<Review>::iterator pr;
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);
		
		vector <Review> oldlist(books);
		if (num > 3) {
			books.erase(books.begin() + 1, books.begin() + 3);
			cout << "After erasure:\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
			books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
			cout << "After insertion:\n";
			for (pr = books.begin(); pr != books.end(); pr++)
				ShowReview(*pr);
		}
		books.swap(oldlist);
		cout << "Swapping oldlist with books:\n";
		for (pr = books.begin(); pr != books.end(); pr++)
			ShowReview(*pr);
	}
	else {
		cout << "Nothing enteren, nothing gained.\n";
	}
	return 0;
}


bool FillReview(Review & rr)
{
	std::cout << "Enter book title (quit to quit): ";
	std::getline(std::cin, rr.title);
	if (rr.title == "quit")
		return false;
	std::cout << "Enter book rating: ";
	std::cin >> rr.rating;
	if(!std::cin)
		return false;

	while (std::cin.get() != '\n') 
		continue;

	return true;
}


void ShowReview(const Review & rr)
{
	std::cout << rr.rating << "\t" << rr.title << std::endl;
}

