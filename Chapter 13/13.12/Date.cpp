#include "Date.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Date::Date(int m, int d, int y) : month(m), day(d), year(y)
{
}

void Date::setDate(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}

int Date::getMonth()
{
	return month;
}

int Date::getDay()
{
	return day;
}

int Date::getYear()
{
	return year;
}

