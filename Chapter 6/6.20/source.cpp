#include <iostream>

using namespace std;

bool multiple(int numberA, int numberB);

int main()
{
    cout << "Please input 2 numbers to determine whether they are multiple relationship: ";
    int numberA, numberB;
    cin >> numberA >> numberB;
    string result;
    if (multiple(numberA, numberB))
    {
        result = "";
    }
    else
    {
        result = "not ";
    }
    cout << "The " << numberB << " is " << result << "the multiple of the " << numberA << "." << endl;
    return 0;
}

bool multiple(int numberA, int numberB)
{
    if (numberB % numberA == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}