#include <iostream>

using namespace std;

double integerPower(double base, int exponent);

int main()
{
    cout << "Please input the base: ";
    double base;
    cin >> base;
    cout << "Please input the exponent(integer only): ";
    int exponent;
    cin >> exponent;
    cout << "The result of " << base << "^" << exponent << " is " << integerPower(base, exponent) << "." << endl;
    return 0;
}

double integerPower(double base, int exponent)
{
    if (exponent == 1)
    {
        return base;
    }
    return base * integerPower(base, exponent - 1);
}