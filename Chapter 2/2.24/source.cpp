#include <iostream>
#include <cmath>

using namespace std;

bool isOddNumber(int a)
{
	if (a % 2 == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	int a;
	cout << "Please input a number: ";
	if (cin >> a)
	{
		if (isOddNumber(a))
		{
			cout << "It's an odd number."<< endl;
		}
		else
		{
			cout << "It's an even number." << endl;
		}
	}
	else
	{
		cout << "The numbers are invaild." << endl;
	}
	return 0;
}