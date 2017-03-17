#include <iostream>
#include "DateAndTime.h"

using namespace std;

int main()
{
    DateAndTime dat(23,58,30,3,13,2017);
    for (int i = 0; i < 100; i++)
    {
        dat.printStandard();
        cout << endl;
        dat.tick();
    }
    return 0;
}