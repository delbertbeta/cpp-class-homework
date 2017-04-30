#include "RationalNumber.h"

#include <stdexcept>

using namespace std;

RationalNumber::RationalNumber(int num, int den)
{
	if (num > 0 && den > 0)
	{
		numerator = num;
		denominator = den;
		simplify();
	}
	else
	{
		throw invalid_argument("The numerator and denominator can't be nagative or zero");
	}
}

RationalNumber RationalNumber::operator+(const RationalNumber & r) const
{
	return RationalNumber(r.denominator * numerator + denominator * r.numerator, denominator * r.denominator);
}

RationalNumber RationalNumber::operator-(const RationalNumber &r) const
{
	return RationalNumber(r.denominator * numerator - denominator * r.numerator, denominator * r.denominator);
}

RationalNumber RationalNumber::operator*(const RationalNumber &r) const
{
	return RationalNumber(numerator * r.numerator, denominator * r.denominator);
}

RationalNumber RationalNumber::operator/(const RationalNumber &r) const
{
	return RationalNumber(numerator * r.denominator, denominator * r.numerator);
}

bool RationalNumber::operator>(const RationalNumber &r) const
{
	double num = numerator / denominator;
	double den = r.denominator / denominator;
	return num > den;
}

bool RationalNumber::operator==(const RationalNumber &) const
{
	return numerator == numerator && denominator == denominator;
}

bool RationalNumber::operator>=(const RationalNumber &r) const
{
	return (*this) > r || (*this) == r;
}

bool RationalNumber::operator<=(const RationalNumber &r) const
{
	return !((*this) > r);
}

inline void RationalNumber::simplify()
{
	int n = numerator;
	int d = denominator;
	int t;
	if (n < d) 
	{
		t = n;
		n = d;
		d = t;
	}
	while (t = n % d) 
	{
		n = d;
		d = t;
	}

	numerator /= d;
	denominator /= d;
}

std::ostream & operator<<(std::ostream &os, const RationalNumber &r)
{
	os << r.numerator << " / " << r.denominator;
	return os;
}
