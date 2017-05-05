#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"
class SavingsAccount : public Account
{
public:
	SavingsAccount(double, double);
	virtual double calculateInterest();
private:
	double rate;
};



#endif // !SAVINGSACCOUNT_H
