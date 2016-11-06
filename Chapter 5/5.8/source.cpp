#include <iostream>

using namespace std;

int main()
{
	int totalNumber, minNumber;
	cout << "Please input some numbers in the format (number_amount number_1 number_2 ...): ";
	cin >> totalNumber;
	for (int i = 0; i < totalNumber; i++)
	{
		int temp;
		cin >> temp;
		if (i == 0)
		{
			minNumber = temp;
		}
		else if (temp < minNumber)
		{
			minNumber = temp;
		}
	}
	cout << "The smallest number is " << minNumber << endl;
	return 0;
}