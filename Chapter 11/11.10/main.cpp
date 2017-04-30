#include <iostream>
#include "RationalNumber.h"

using namespace std;

int main()
{
	cout << "Please input the numerator denominator for rational(1): ";
	int num, den;
	cin >> num >> den;
	RationalNumber r1(num, den);
	cout << "Please input the numerator denominator for rational(2): ";
	cin >> num >> den;
	RationalNumber r2(num, den);
	cout << "r1 + r2 = " << r1 + r2 << endl;
	cout << "r1 - r2 = " << r1 - r2 << endl;
	cout << "r1 * r2 = " << r1 * r2 << endl;
	cout << "r1 / r2 = " << r1 / r2 << endl;
	cout << "r1 >= r2 = " << (r1 >= r2 ? "True" : "False") << endl;
	system("pause");
}