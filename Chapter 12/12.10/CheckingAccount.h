#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H


#include "Account.h"


class CheckingAccount : public Account
{
public:
	CheckingAccount(double, double);
	bool credit(double);
	bool debit(double);

private:
	double fee;
};



#endif // !CHECKINGACCOUNT_H

