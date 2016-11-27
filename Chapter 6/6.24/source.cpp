#include <iostream>

using namespace std;

class numberSeparater
{
private:
	static int getQuotient(int a, int b)
	{
		return a / b;
	}
	static int getRemainder(int a, int b)
	{
		return a % b;
	}
public:
	static void separateNumber(short outputArray[], short inputNumber)
	{
		for (int i = 0; i <= 5; i++)
		{
			short digit = getRemainder(inputNumber, 10);
			outputArray[4 - i] = digit;
			inputNumber = getQuotient(inputNumber, 10);
		}
	}
};

int main()
{
	cout << "Please input a number(from 1 to 32767): ";
	short number;
	cin >> number;
	short digits[5];
	numberSeparater::separateNumber(digits, number);
    bool isZero = true;
	for (int i = 0; i <= 4; i++)
	{
        if (isZero)
        {
            if (digits[i] == 0)
            {
                isZero = true;
            }
            else
            {
                isZero = false;
            }
        }
        if (!isZero)
		{
            cout << digits[i] << "  ";
        }
	}
    cout << endl;
	return 0;
}
