#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	for (double rate = .05; rate <= .1; rate += 0.01)
	{
		cout << "The procedure with the rate of " << setprecision(0) << rate * 100 << "%" << endl;
		double amount, principal = 1000.0;

		cout << "Year" << setw(21) << "Amount on deposit" << endl;

		cout << fixed << setprecision(2);

		for (int year = 1; year <= 10; ++year)
		{
			amount = principal * pow(1.0 + rate, year);
			cout << setw(4) << year << setw(21) << amount << endl;
		}
		cout << endl;
	}
	return 0;
}
