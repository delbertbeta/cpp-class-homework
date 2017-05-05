#ifndef DATE_H
#define DATE_H

class Date
{
public:
	Date(int m = 1, int d = 1, int y = 1900);
	void setDate(int, int, int);
	int getMonth();
	int getDay();
	int getYear();
private:
	int month;
	int day;
	int year;
};



#endif // !DATE_H
