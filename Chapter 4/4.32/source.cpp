#include <iostream>

using namespace std;

int main()
{
	double a, b, c;
	cout << "Please input three numbers to determine whether they could represent the sides of a triangle: " << endl;
	if (cin >> a >> b >> c)
	{
		if (a > 0 && b > 0 && c > 0)
		{
			if (a + b > c && b + c > a && a + c > b)
			{
				cout << "They are the sides of a triangle." << endl;
			}
			else
			{
				cout << "They are not the sides of a triangle." << endl;
			}

		}
		else
		{
			cout << "the numbers you entered are invalid..." << endl;
			return 1;
		}
	}
	else
	{
		cout << "the numbers you entered are invalid..." << endl;
		return 1;
	}
	return 0;
}
