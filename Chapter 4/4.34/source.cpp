#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void chooseFunction(short& functionNumber);
long computeFactorial(short n);
double computeE(short n);
double computeEX(short n, short x);

int main()
{
	cout << "1. Compute a nonnegative interger\'s factorial." << endl;
	cout << "2. Estimate the value of the mathematical constant e." << endl;
	cout << "3. Compute the value of e^x." << endl;

	short functionNumber;
	chooseFunction(functionNumber);

	while (functionNumber != -1)
	{
		switch (functionNumber)
		{
		case 1:
		{
			cout << "Please input a nonnegative integer: ";
			short number;
			if (cin >> number)
			{
				long result = computeFactorial(number);
				cout << number << "\'s factorial is " << result << endl;
			}
			break;
		}

		case 2:
		{
			cout << "Please input the accuracy: ";
			short accuracy;
			if (cin >> accuracy)
			{
				double result = computeE(accuracy);
				cout << "Result of e in accuracy of " << accuracy << " is: " << fixed << setprecision(6) << result << endl;
			}
			break;
		}

		case 3:
		{
			cout << "Please input the accuracy: ";
			short accuracy;
			cin >> accuracy;
			cout << "Please input the x: ";
			short x;
			cin >> x;
			if (cin)
			{
				double result = computeEX(accuracy, x);
				cout << "The result of e^" << x << " is " << result << endl;
			}
			break;
		}
		default:
		{
			cout << "Sorry, we haven't developed this function...." << endl;
			break;
		}
		}
		cin.clear();
		chooseFunction(functionNumber);
	}
	return 0;
}

void chooseFunction(short& functionNumber)
{
	cout << "\nChoose a function to go on (1, 2 ,3 or -1 to quit): ";
	cin >> functionNumber;
}

long computeFactorial(short n)
{
	if (n == 1)
		return 1;
	return n * computeFactorial(n - 1);
}

double computeE(short n)
{
	if (n == 0)
	{
		return 1.0;
	}
	double temp = 1.0 / computeFactorial(n);
	return temp + computeE(n - 1);
}

double computeEX(short n, short x)
{
	if (n == 0)
	{
		return 1.0;
	}
	double temp = (double)pow(x, n) / computeFactorial(n);
	return temp + computeEX(n - 1, x);
}
