#ifndef GOLF_H_
#define GOLF_H_
class Golf{
private:

	static const int Len = 40;
	char fullname[Len];
	int handicap;
public:
	Golf();
	Golf(const char * name, int hc);
	void setgolf(const char * name, int hc);
//	int setgolf();
	void sethandicap(int hc);
	void showgolf() const;
};
#endif
