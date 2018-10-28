/*
cin 通过 blank,\t,\n来确定字符串结束位置
*/
/*
cin.getline(arrname, N):最多读取N-1个字符到arrname中
cin.getline()读取整行，通过回车键输入的换行符确定输入结尾
RK: getline会将缓冲区的换行符直接读入结束输入！getline会读取换行符，但是会把它替换为空
试一下如果超出N-1输入
*/
/*
cin.get(arrname, N):类似getline，但是换行符将留在输入缓冲区！
cin.get(无参数):读取下一个字符，哪怕是换行符
留换行符的办法使得我们可以通过检查队列里第一个字符来确定cin是得到N-1个字符停止还是得到一行而停止
*/
#include <iostream>
int main()
{
	using namespace std;
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];
	cout << "When we use cin:" << endl;
	cout << "Please enter your name:\n";
	cin >> name;
	cout << "Please enter your favorite dessert:\n";
	cin >> dessert;
	cout << "I have some delicious " << dessert << " for you, " << name << endl; // Ya ya,对name而言cin捕捉Ya,而把ya放在输入队列，被dessert捕捉到。 

	cin.sync();	// 清空输入缓存 

	cout << "When we use getline:" << endl;
	cout << "Please enter your name:\n";
	cin.getline(name, ArSize);
	cout << "Please enter your favorite dessert:\n";
	cin.getline(dessert, ArSize);
	cout << "I have some delicious " << dessert << " for you, " << name << endl;

	cin.sync();
	cout << "When we use get:" << endl;
	cout << "Please enter your name:\n";
	cin.get(name, ArSize);
	cout << "Please enter your favorite dessert:\n";
	cin.get(); // tricky one
	cin.get(dessert, ArSize);
	cout << "I have some delicious " << dessert << " for you, " << name << endl;

	return 0;
}