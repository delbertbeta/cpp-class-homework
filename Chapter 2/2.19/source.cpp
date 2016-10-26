#include <iostream>

using namespace std;

int findMinInt(int a, int b, int c)
{
	int minInt;
	if (a < b)
	{
		minInt = a;
	}
	else
	{
		minInt = b;
	}
	if (minInt < c)
	{
		return minInt;
	}
	else
	{
		return c;
	}
}

int findMaxInt(int a, int b, int c)
{
	int maxInt;
	if (a > b)
	{
		maxInt = a;
	}
	else
	{
		maxInt = b;
	}
	if (maxInt > c)
	{
		return maxInt;
	}
	else
	{
		return c;
	}
}

int main()
{
	int a, b, c;
	cout << "Input three different integers: ";
	if (cin >> a >> b >> c)
	{
		cout << "Sum is " << a + b + c << endl;
		cout << "Average is " << (a + b + c) / 3 << endl;
		cout << "Product is " << a * b * c << endl;
		cout << "Smallest is " << findMinInt(a, b, c) << endl;
		cout << "Largest is " << findMaxInt(a, b, c) << endl;
	}
	else
	{
		cout << "The numbers are invaild." << endl;
	}
	return 0;
}