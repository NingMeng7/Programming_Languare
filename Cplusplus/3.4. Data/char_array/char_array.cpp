//  对C-style的数组字符串，在初始化的时候可以用 '='
//  而在之后进行赋值应该使用strcpy(charr1,charr2)  strncpy(charr1,charr2,n) 最多复制n个字符到charr1，而后自动补'\0'

#include <iostream>
#include <cstring>

int main()
{
	using namespace std;
	char dog[8] = { 'f', 'a', 't', 'e', 's', 's', 'a', '\0' };  // '\0' is necessary
	char bird[11] = "Mr.cheeps";
	char fish[] = "Bubble";

	cout << "I'd give my right arm to be" " a great violinist.\n";

	cin >> bird;
	cout << bird;
	return 0;
}