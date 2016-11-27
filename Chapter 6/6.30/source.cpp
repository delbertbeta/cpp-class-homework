#include <iostream>

using namespace std;

int reverseDigit(int number);

int main()
{
    int number;
    cout << "Please input a number to reverse it: ";
    cin >> number;
    cout << "The reversed number is " << reverseDigit(number) << "." << endl;
    return 0;
}

int reverseDigit(int number)
{
    int result = 0;
    while (number != 0)
    {
        result = result * 10 + number % 10;
        number = number / 10;
    }
    return result;
}