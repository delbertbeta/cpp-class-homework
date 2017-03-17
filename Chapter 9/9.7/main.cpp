#include <iostream>
#include "Time.h"

using namespace std;

int main()
{
    Time t1(23,59,50);
    for (int i = 0; i < 100; i++)
    {
        t1.printStandard();
        cout << endl;
        t1.tick();
    }
}