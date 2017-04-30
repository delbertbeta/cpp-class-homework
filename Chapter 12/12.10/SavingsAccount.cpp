#include "SavingsAccount.h"
#include <stdexcept>

using namespace std;


SavingsAccount::SavingsAccount(double b, double r): Account(b)
{
	if (rate > 0)
	{
		rate = r;
	}
	else
	{
		throw invalid_argument("rate must be positive.");
	}
}

double SavingsAccount::calculateInterest()
{
	return rate * balance;
}

