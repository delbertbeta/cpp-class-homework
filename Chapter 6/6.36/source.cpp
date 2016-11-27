#include <iostream>

using namespace std;

long power(int base, int exponent);

int main()
{
    cout << "Please input the base and the exponent(format: base exponent): ";
    int base, exponent;
    cin >> base >> exponent;
    cout << "The result of " << base << "^" << exponent << " is " << power(base, exponent) << "." << endl;
    return 0;
}

long power(int base, int exponent)
{
    if (exponent == 1)
    {
        return base;
    }
    return base * power(base, exponent - 1);
}