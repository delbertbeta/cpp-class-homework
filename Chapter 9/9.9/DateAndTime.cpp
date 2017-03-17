#include <iostream>
#include <stdexcept>
#include <iomanip>
#include "DateAndTime.h"

using namespace std;

DateAndTime::DateAndTime(int h, int m, int s, int mon, int d, int y)
{
    month = mon;
    day = d;
    year = y;
    hour = h;
    minute = m;
    second = s;
}

void DateAndTime::nextDay()
{
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day == 31)
        {
            day = 1;
            if (month == 12)
            {
                month = 1;
                year++;
            }
            else 
            {
                month++;
            }
        }
        else 
        {
            day++;
        }
    } else if (month == 2) 
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            if (day == 29)
            {
                day = 1;
                month++;
            }
            else 
            {
                day++;
            }
        }
        else 
        {
            if (day == 28)
            {
                day = 1;
                month++;
            }
            else
            {
                day++;
            }
        }
    } else 
    {
        if (day == 30)
        {
            day = 1;
            month++;
        }
        else 
        {
            day++;
        }
    }
}

void DateAndTime::setTime(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}

void DateAndTime::setHour(int h) 
{
    if (h >= 0 && h < 24)
    {
        hour = h;
    }
    else
    {
        throw invalid_argument("hour mustbe 0-23");
    }
}

void DateAndTime::setMinute(int m)
{
    if (m >= 0 && m < 60)
    {
        minute = m;
    }
    else 
    {
        throw invalid_argument("minute must be 0-59");
    }
}

void DateAndTime::setSecond(int s)
{
    if (s >= 0 && s < 60)
    {
        second = s;
    }
    else
    {
        throw invalid_argument("second must be 0-59");
    }
}

int DateAndTime::getHour()
{
    return hour;
}

int DateAndTime::getMinute()
{
    return minute;
}

int DateAndTime::getSecond()
{
    return second;
}

void DateAndTime::printUniversal()
{
    cout << setfill('0') << setw(2) << getHour() << ":" << setw(2) << getMinute() << ":" << setw(2) << getSecond() << " ";
    cout << month << '/' << day << '/' << year;
}

void DateAndTime::printStandard()
{
    cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12) << ":" << setfill('0') << setw(2) << getMinute() << ":" << setw(2) << getSecond() << (getHour() < 12 ? "AM" : "PM") << " ";
    cout << month << '/' << day << '/' << year;
}

void DateAndTime::tick()
{
    if (second == 59)
    {
        second = 0;
        if (minute == 59)
        {
            minute = 0;
            if (hour == 23)
            {
                hour = 0;
                nextDay();
            }
            else {
                hour++;
            }
        }
        else {
            minute++;
        }
    } else {
        second++;
    }
}