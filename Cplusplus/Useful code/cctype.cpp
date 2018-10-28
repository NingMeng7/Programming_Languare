isalnum() 如果参数是字母或者数字
isalpha() 如果参数是字母
iscntrl() 如果参数是控制字符
isdigit() 如果参数是数字(0~9)
isgraph() 如果参数是除空格之外的打印字符
islower() 如果参数是小写字母
isprint() 如果参数是打印字符(包括打印字符)
ispunct() 如果参数是标点符号
isspace() 如果参数是标准空白字符，like空格、进纸、换行符、回车、水平制表符、垂直制表符
isupper() 如果参数是大写字母
isxdigit() 如果参数是十六进制数字
tolower() 如果参数是大写字符，返回其小写，否则返回该参数
toupper() 如果参数是小写字符，返回其大写，否则返回该参数


#include <iostream>
#include <cctype>
int main()
{
	using namespace std;
	cout << "Please enter text for analysis, and quit with EOF!" << endl;
	char ch;
	int whitespace = 0;
	int digits = 0;
	int chars = 0;
	int punct = 0;
	int others = 0;

	cin.get(ch);
	while (cin.get(ch)) {
		if (isalpha(ch))
			chars++;
		else if (isspace(ch)) {
			whitespace++;
		}
		else if (isdigit(ch))
			digits++;
		else if (ispunct(ch)) {
			punct++;
		}
		else {
			others++;
		}
	}
	cout << chars << "letters, " << whitespace << " whitespace, " << digits << " digits， " << punct << " punctuations, " << others << " others."
		<< endl;
	while (cin.get() != 'q') 
		;
	return 0;
}
