#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double gross;
	const double fixedSalary = 200;

	cout << "Enter sales in dollars (-1 to quit): ";
	cin >> gross;
	while (gross != -1)
	{
		cout << "Salary is: $" << fixed << setprecision(2) << gross * 0.09 + fixedSalary << endl;

		cout << "\nEnter sales in dollars (-1 to quit): ";
		cin >> gross;
	}
	return 0;
}