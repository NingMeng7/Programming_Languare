#include <iostream>
#include "golf.h"
const int Max = 5;
int main()
{
	golf golfer[Max];
	int i;
	for (i = 0; i < Max; i++) {
		if (!setgolf(golfer[i]))
			break;
	}
	for (int j = 0; j < i; j++) {
		showgolf(golfer[j]);
	}
	golf ann;
	setgolf(ann, "Ann Birdfree", 24);
	showgolf(ann);
	handicap(ann, 10);
	showgolf(ann);
	while (std::cin.get() != 'q')
		;
	return 0;
}