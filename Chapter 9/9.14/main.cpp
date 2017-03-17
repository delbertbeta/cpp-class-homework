#include <iostream>
#include "HugeInteger.h"

using namespace std;

int main()
{
	HugeInteger hi1;
	HugeInteger hi2;
	cout << "Please input the numbers for huge integer 1(max length is 40 and use any character at end of the integer to present the end of the integer): ";
	hi1.input();
	cout << "Please input the numbers for huge integer 2(max length is 40 and use any character at end of the integer to present the end of the integer): ";
	hi2.input();
	cout << "Huge integer 1 is: ";
	hi1.output();
	cout << endl << "Huge integer 2 is: ";
	hi2.output();
	cout << endl << "After hi1 + hi2, hi1 = ";
	hi1.add(hi2);
	hi1.output();
	cout << endl << "After hi1 - hi2, hi1 = ";
	hi1.subtract(hi2);
	hi1.output();
	cout << endl << "hi1 is " << (hi1.isGreaterThanOrEqualTo(hi2) ? "\b" : "not") << " greater than or equal to hi2" << endl;
	// system("pause");
	return 0;
}