#include "CheckingAccount.h"
#include <stdexcept>

using namespace std;

CheckingAccount::CheckingAccount(double b, double f) : Account(b)
{
	if (f >= 0)
	{
		fee = f;
	}
	else {
		throw invalid_argument("Fee must be positive.");
	}
}

bool CheckingAccount::credit(double b)
{
	if (Account::credit(b))
	{
		balance -= fee;
	}
	else {
		return false;
	}

}

bool CheckingAccount::debit(double b)
{
	if (Account::debit(b))
	{
		balance -= fee;
	}
	else
	{
		return false;
	}
}
