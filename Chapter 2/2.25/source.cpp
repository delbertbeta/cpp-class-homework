#include <iostream>
#include <cmath>

using namespace std;

bool isMultipleNumber(int a, int b)
{
	if (a % b == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int a, b;
	cout << "Please input 2 numbers: ";
	if (cin >> a >> b)
	{
		if (isMultipleNumber(a, b))
		{
			cout << a << " is a multiple of " << b << endl;
		}
		else
		{
			cout << a << " is not a multiple of " << b << endl;
		}
	}
	else
	{
		cout << "The numbers are invaild." << endl;
	}
	return 0;
}