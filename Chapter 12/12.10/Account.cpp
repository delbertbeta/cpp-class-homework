#include "Account.h"
#include <stdexcept>
#include <iostream>

using namespace std;

Account::Account(double b)
{
	if (b >= 0.0)
	{
		balance = b;
	}
	else
	{
		b = 0.0;
		cout << "The blance can't be nagative, so it has been reset to 0.0 .";
	}

}

bool Account::credit(double b)
{
	if (b > 0)
	{
		balance += b;
		return true;
	}
	else
	{
		return false;
	}

}

bool Account::debit(double b)
{
	if (b < balance && b > 0)
	{
		balance -= b;
		return true;
	}
	else 
	{
		return false;
	}

}

double Account::getBalance()
{
	return balance;
}
