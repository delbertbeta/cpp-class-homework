#include <iostream>
#include "Date.h"

using namespace std;

Date::Date(int m, int d, int y)
{
    month = m;
    day = d;
    year = y;
}

void Date::print()
{
    cout << month << '/' << day << '/' << year;
}

void Date::nextDay()
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