#include <iostream>

using namespace std;

int main()
{
	cout << "Please input two numbers: ";
	int a, b;
	if (cin >> a >> b)
	{
		cout << "a + b = " << a + b << endl;
		cout << "a * b = " << a * b << endl;
		cout << "a - b = " << a - b << endl;
		cout << "a / b = " << a / b << endl;
	}
	else
	{
		cout << "The numbers are invalid" << endl;
	}
	return 0;
}
