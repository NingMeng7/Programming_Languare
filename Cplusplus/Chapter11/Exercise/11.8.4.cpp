friend Stonewt operator*(double x, const Stonewt & s);

Stonewt operator*(double x, const Stonewt & s)
{
	return Stonewt(mult * s.pounds);
}


