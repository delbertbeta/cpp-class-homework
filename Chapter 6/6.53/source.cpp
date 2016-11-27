#include <iostream>

using namespace std;

template<typename T>
T minimum(T para1, T para2)
{
    return para1 < para2 ? para1 : para2;
}

int main()
{
    cout << "Please input two integers: ";
    int intA, intB;
    cin >> intA >> intB;
    int minInt = minimum(intA, intB);
    cout << "The minimum integer is " << minInt << "." << endl;
    cout << "Please input two chars: ";
    char charA, charB;
    cin >> charA >> charB;
    char minChar = minimum(charA, charB);
    cout << "The minimum char is " << minChar << "." << endl;
    cout << "Please input two float-point numbers: ";
    double doubleA, doubleB;
    cin >> doubleA >> doubleB;
    double minDouble = minimum(doubleA, doubleB);
    cout << "The minimum float-point numbers is " << minDouble << "." << endl;
    return 0;
}