#include <iostream>
int main()
{
	char ch;
	std::cout << "Type, and I shall repeat.\n";
	std::cin.get(ch);
	while (ch != '.') {
		if (ch == '\n')
			std::cout << ch;
		else {
			std::cout << ch + 1;  //  ½«Êä³öASCIIÂë
								  //std::cout << ++ch;  
		}
		std::cin.get(ch);
	}
	return 0;
}