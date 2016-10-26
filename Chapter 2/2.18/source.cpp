#include <iostream>

using namespace std;

int main()
{
	int a, b;
	cout << "Please input two numbers: ";
	if (cin >> a >> b)
	{
		int largerInt;
		if (a > b)
		{
			largerInt = a;
		}
		else
		{
			largerInt = b;
		}
		if (a == b)
		{
			cout << "These numbers are equal." << endl;
		}
		else
		{
			cout << largerInt << " is larger." << endl;
		}
	}
	else
	{
		cout << "The numbers are invalid." << endl;
	}
	return 0;
}
