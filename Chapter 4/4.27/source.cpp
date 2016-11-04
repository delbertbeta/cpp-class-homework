#include <iostream>
#include <string>
#include <iterator>
#include <stdexcept>

using namespace std;

int binToDecConverter(string binaryNumber);

int main()
{
	string binaryNumber;
	cout << "Please input a binary number (e.g 1010101): ";
	cin >> binaryNumber;
	int decimalNumber;
	try
	{
		decimalNumber = binToDecConverter(binaryNumber);
	}
	catch (invalid_argument e)
	{
		cout << "The binary number you entered is invaild..." << endl;
		return 1;
	}
	cout << "The decimal equivalent of " << binaryNumber << " is " << decimalNumber << "." << endl;
	return 0;
}

int binToDecConverter(string binaryNumber)
{
	int decimalNumeber = 0;
	int baseBinary = 1;
	string::reverse_iterator iter = binaryNumber.rbegin();
	while (iter != binaryNumber.rend())
	{
		short digit = ((int)(*iter++) - 48);
		if (digit != 0 || digit != 1)
		{
			throw invalid_argument("unexpected digit");
		}
		decimalNumeber += baseBinary * digit;
		baseBinary *= 2;
	}
	cout << decimalNumeber << endl;
	return decimalNumeber;
}
