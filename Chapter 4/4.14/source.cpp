#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int accountNumber;
	double beginningBalance, totalCharges, totalCredits, creditLimit;

	cout << "Enter account number (-1 to quit): ";
	cin >> accountNumber;
	while (accountNumber != -1)
	{
		cout << "Enter beginning balance: ";
		cin >> beginningBalance;
		cout << "Enter total charges: ";
		cin >> totalCharges;
		cout << "Enter total credits: ";
		cin >> totalCredits;
		cout << "Enter credit limit: ";
		cin >> creditLimit;
		
		double newBalance = beginningBalance + totalCharges - totalCredits;

		cout << "New balance is " << fixed << setprecision(2) << newBalance << endl;

		if (newBalance > creditLimit)
		{
			cout << "Account:\t" << accountNumber << endl;
			cout << "Credit limit:\t" << creditLimit << endl;
			cout << "Balance:\t" << newBalance << endl;
			cout << "Credit Limit Exceeded." << endl;
		}

		cout << "\nEnter account number (-1 to quit): ";
		cin >> accountNumber;
	}
	return 0;
}