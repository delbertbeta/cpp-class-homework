#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
	Account(double);
	bool credit(double);
	bool debit(double);
	double getBalance();
protected:
	double balance;

};



#endif // !ACCOUNT_H

