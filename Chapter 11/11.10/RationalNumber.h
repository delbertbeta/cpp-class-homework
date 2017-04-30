#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <iostream>

class RationalNumber
{
public:
	RationalNumber(int, int);
	RationalNumber operator +(const RationalNumber&) const;
	RationalNumber operator -(const RationalNumber&) const;
	RationalNumber operator *(const RationalNumber&) const;
	RationalNumber operator /(const RationalNumber&) const;
	bool operator >(const RationalNumber&) const;
	bool operator ==(const RationalNumber&) const;
	bool operator >=(const RationalNumber&) const;
	bool operator <=(const RationalNumber&) const;
	friend std::ostream& operator<<(std::ostream&, const RationalNumber&);
private:
	int numerator;
	int denominator;
	void simplify();
};


#endif // !RATIONALNUMBER_H
