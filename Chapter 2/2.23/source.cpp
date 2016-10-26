#include <iostream>
#include <cmath>

using namespace std;

int findMaxInt(int a, int b, int c, int d, int e)
{
	int MaxInt;
	if (a > b)
		MaxInt = a;
	else
		MaxInt = b;
	if (MaxInt < c)
		MaxInt = c;
	if (MaxInt < d)
		MaxInt = d;
	if (MaxInt < e)
		MaxInt = e;
	return MaxInt;
}

int findMinInt(int a, int b, int c, int d, int e)
{
	int MinInt;
	if (a < b)
		MinInt = a;
	else
		MinInt = b;
	if (MinInt > c)
		MinInt = c;
	if (MinInt > d)
		MinInt = d;
	if (MinInt > e)
		MinInt = e;
	return MinInt;
}

int main()
{
	int a, b, c, d, e;
	cout << "Please input 5 numbers: ";
	if (cin >> a >> b >> c >> d >> e)
	{
		cout << "The largest is " << findMaxInt(a, b, c, d, e) << endl;
		cout << "The smallest is " << findMinInt(a, b, c, d, e) << endl;
	}
	else
	{
		cout << "The numbers are invaild." << endl;
	}
	return 0;
}