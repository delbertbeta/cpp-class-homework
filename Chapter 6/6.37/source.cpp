#include <iostream>
#include <ctime>

using namespace std;

int fibonacci(int n);
double fibonacciDouble(double n);

int main()
{
	int i = 1;
	int lastFibonacciNumber;
	do
	{
		int fibonacciNumber = fibonacci(i);
		if (fibonacciNumber < 0)
		{
			break;
		}
		lastFibonacciNumber = fibonacciNumber;
		i++;
	} while (true);
	cout << "The largest fibonacci number that int type can store is " << lastFibonacciNumber << "." << endl;

	double doubleI = 1;
	double doubleLastFibonacciNumber = 0;
	double startTime = (double)clock();
    bool isTheLargest = true;
	do
	{
		double fibonacciNumber = fibonacciDouble(i);
		if (fibonacciNumber < 0)
		{
			break;
		}
		double nowTime = (double)clock();
		if (nowTime - startTime >= 100000)
		{
			cout << "Time out... Stopped computing...\n";
            isTheLargest = false;
			break;
		}
		doubleLastFibonacciNumber = fibonacciNumber;
		doubleI++;
	} while (true);
    if (isTheLargest)
	    cout << "The largest fibonacci number that double type can store is " << doubleLastFibonacciNumber << "." << endl;
    else
        cout << "The last computed fibonacci number is " << doubleLastFibonacciNumber << "." << endl;
	return 0;
}

int fibonacci(int n)
{
	int first = 0, second = 1, fibonacciN = 0;
	if (n == 1)
	{
		return first;
	}
	if (n == 2)
	{
		return second;
	}
	for (int i = 3; i <= n; i++)
	{
		fibonacciN = first + second;
		first = second;
		second = fibonacciN;
	}
	return fibonacciN;
}

double fibonacciDouble(double n)
{
	double first = 0, second = 1;
	double fibonacciN = 0;
	if (n == 1)
	{
		return first;
	}
	if (n == 2)
	{
		return second;
	}
	for (double i = 3; i <= n; i++)
	{
		fibonacciN = first + second;
		first = second;
		second = fibonacciN;
	}
	return fibonacciN;
}