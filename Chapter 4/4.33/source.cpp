#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cout << "Please input three numbers to determine whether it\'s a right triangle: " << endl;
	if (cin >> a >> b >> c)
	{
		if (a > 0 && b > 0 && c > 0)
		{
			if (a + b > c && b + c > a && a + c > b)
			{
				if (a * a + b * b == c * c || b * b + c * c == a * a || a * a + c * c == b * b)
				{
					cout << "This is a right triangle." << endl;
				}
				else
				{
					cout << "This is not a right triangle." << endl;
				}
			}
			else
			{
				cout << "They are not the sides of a triangle." << endl;
			}

		}
		else
		{
			cout << "They are not the sides of a triangle." << endl;
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
