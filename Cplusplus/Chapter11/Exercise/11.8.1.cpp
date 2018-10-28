/*************************************************************************
    > File Name: 11.8.1.cpp
    > Author: JY.ZH
    > Mail: xw2016@mail.ustc.edu.cn 
    > Created Time: 2018年07月29日 星期日 20时58分25秒
 ************************************************************************

Stonewt operator*(double x);

Stonewt Stonewt::operator*(double x) const
{
	return Stonewt(x * pounds);
}
