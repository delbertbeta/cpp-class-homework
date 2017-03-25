#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Time.h"

using namespace std;

Time::Time(int hr, int min, int sec)
{
	second = 0;
	setTime(hr, min, sec);
}

Time &Time::setTime(int h, int m, int s)
{
	setHour(h);
	setMinute(m);
	setSecond(s);
	return *this;
}

Time &Time::setHour(int h)
{
	if (h >= 0 && h < 24)
	{
		second = getSecond() + getMinute() * 60 + h * 3600;
	}
	else
	{
		throw invalid_argument("hour must be 0-23");
	}
	return *this;
}

Time &Time::setMinute(int m)
{
	if (m >= 0 && m < 60)
	{
		second = getSecond() + m * 60 + getHour() * 3600;
	}
	else
	{
		throw invalid_argument("minute must be 0-59");
	}
	return *this;
}

Time &Time::setSecond(int s)
{
	if (s >= 0 && s < 60)
	{
		second = s + getMinute() * 60 + getHour() * 3600;
	}
	else
	{
		throw invalid_argument("second must be 0-59");
	}
	return *this;
}

int Time::getHour() const
{
	return second / 3600;
}

int Time::getMinute() const
{
	return (second / 60) % 60;
}

int Time::getSecond() const
{
	return second % 60;
}

void Time::printUniversal() const
{
	cout << setfill('0') << setw(2) << getHour() << ":" << setw(2) << getMinute() << ":" << setw(2) << getSecond();
}

void Time::printStandard() const
{
	cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":" << setfill('0') << setw(2) << getMinute() << ":" << setw(2) << getSecond() << (getHour() < 12 ? "AM" : "PM");
}