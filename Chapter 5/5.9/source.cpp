#include <iostream>

using namespace std;

int main()
{
	int product = 1;
	for (int i = 1; i <= 15; i++)
	{
		if (i % 2 == 1)
		{
			cout << i << " * ";
			product *= i;
		}
	}
	cout << "\b\b= " << product;
	return 0;
}
