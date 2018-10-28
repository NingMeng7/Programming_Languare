operator double() const;

Vector::operator double() const
{
	return mag;
}



//	内联形式
operator double()
{
	return mag;
}
