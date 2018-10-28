/*************************************************************************
    > File Name: Move.h
    > Author: JY.ZH
    > Mail: xw2016@mail.ustc.edu.cn 
    > Created Time: 2018年07月19日 星期四 15时08分00秒
 ************************************************************************/

class Move
{
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0);
	void showmove() const;
	Move add(const Move & m) const;
	void reset(double a = 0, double b = 0);
};


