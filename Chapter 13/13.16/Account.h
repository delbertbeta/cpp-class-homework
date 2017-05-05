#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
	Account(double);
	virtual bool credit(double);
	virtual bool debit(double);
	virtual double getBalance();
protected:
	double balance;

};



#endif // !ACCOUNT_H

