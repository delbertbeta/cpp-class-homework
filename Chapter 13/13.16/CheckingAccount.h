#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H


#include "Account.h"


class CheckingAccount : public Account
{
public:
	CheckingAccount(double, double);
	virtual bool credit(double);
	virtual bool debit(double);

private:
	double fee;
};



#endif // !CHECKINGACCOUNT_H

