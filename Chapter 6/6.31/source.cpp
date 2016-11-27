#include <iostream>

using namespace std;

int gcd(int number_1, int number_2);

int main()
{
    cout << "Please input the number_1: ";
    int number_1;
    cin >> number_1;
    cout << "Please input the number_1: ";
    int number_2;
    cin >> number_2;
    cout << "The greatest common divisor of two numbers is " << ((number_1 > number_2) ? (gcd(number_1, number_2)) : (gcd(number_2, number_1))) << "." << endl;
    return 0;
}

int gcd(int number_1, int number_2)
{
    while (number_1 % number_2 != 0)
    {
        int mod = number_1 % number_2;
        number_1 = number_2;
        number_2 = mod;
    }
    return number_2;
}