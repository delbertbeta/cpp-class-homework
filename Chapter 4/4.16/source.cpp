#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int hours;
	double salaryRate = 200;

	cout << "Enter hours worked (-1 to end): ";
	cin >> hours;
	while (hours != -1)
	{
		cout << "Enter hourly rate of the employee ($00.00): ";
		cin >> salaryRate;
		double salary;
		if (hours <= 40)
		{
			salary = salaryRate * hours;
		}
		else
		{
			salary = (40 + (hours - 40) * 1.5) * salaryRate;
		}
		cout << "Salary is: $" << fixed << setprecision(2) << salary << endl;

		cout << "\nEnter hours worked (-1 to end): ";
		cin >> hours;
	}
	return 0;
}