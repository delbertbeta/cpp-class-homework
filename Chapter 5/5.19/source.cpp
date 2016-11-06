#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "Times\tPi" << endl;
	double pi = 0;
	for (int i = 1; i <= 1000; i++)
	{
		double temp = 4.0 / (i * 2 - 1);
		if (i % 2 == 1)
		{
			pi += temp;
		}
		else
		{
			pi -= temp;
		}
		cout << i << "\t" << pi << endl;
	}
	return 0;
}
