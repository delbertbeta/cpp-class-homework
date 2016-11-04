#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int passes = 0, failures = 0, studentCounter = 1, result;
	double salaryRate = 200;

	while (studentCounter <= 10)
	{
		cout << "Enter result (1 = pass, 2 = fail): ";
		cin >> result;

		while (result != 1 && result != 2)
		{
			cout << "Please input a valid number: ";
			cin >> result;
		}

		if (result == 1)
		{
			passes++;
		}
		else
		{
			failures++;
		}
		
		studentCounter++;
	}

	cout << "Passed " << passes << "\nFailed " << failures << endl;
	if (passes > 8)
	{
		cout << "Bonus to instructor!" << endl;
	}

	return 0;
}