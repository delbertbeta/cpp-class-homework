#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

#include <iostream>

using namespace std;

int main()
{
	double balance, fee, rate, debit, credit;

	cout << "Input the balance: ";
	cin >> balance;
	cout << "Input the fee for checking account: ";
	cin >> fee;
	cout << "Input the rate for savings account: ";
	cin >> rate;
	cout << "Input the money to test debit function: ";
	cin >> debit;
	cout << "Input the money to test credit function: ";
	cin >> credit;


	Account account(balance);
	SavingsAccount savingsAccount(balance, rate);
	CheckingAccount checkingAccount(balance, fee);


	cout << "The balance of a normal account: " << account.getBalance() << "." << endl;
	account.credit(credit);
	cout << "When it get the credit, the balance is: " << account.getBalance() << '.' << endl;
	account.debit(debit);
	cout << "When it withdraw the debit, the balance is: " << account.getBalance() << '.' << endl;


	cout << "The balance of a savings account: " << savingsAccount.getBalance() << "." << endl;
	savingsAccount.credit(credit);
	cout << "When it get the credit, the balance is: " << savingsAccount.getBalance() << '.' << endl;
	savingsAccount.debit(debit);
	cout << "The final interest the savings account will get is: " << savingsAccount.calculateInterest() << "." << endl;
	cout << "When it withdraw the debit, the balance is: " << savingsAccount.getBalance() << '.' << endl;


	cout << "The balance of a checking account: " << checkingAccount.getBalance() << "." << endl;
	checkingAccount.credit(credit);
	cout << "When it get the credit, the balance is: " << checkingAccount.getBalance() << '.' << endl;
	checkingAccount.debit(debit);
	cout << "When it withdraw the debit, the balance is: " << checkingAccount.getBalance() << '.' << endl;


	system("pause");

}