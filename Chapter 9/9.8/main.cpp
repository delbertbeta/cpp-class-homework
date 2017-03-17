#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
    Date d1(2,1,2015);
    for (int i = 0; i < 100; i++)
    {
        d1.print();
        cout << endl;
        d1.nextDay();
    }
    Date d2(11,1,2015);
    for (int i = 0; i < 100; i++)
    {
        d2.print();
        cout << endl;
        d2.nextDay();
    }
}