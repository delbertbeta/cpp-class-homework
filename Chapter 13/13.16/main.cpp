#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"

#include <iostream>
#include <vector>

using namespace std;

void accountHandle(Account* account);
void display(Account* account);

int main()
{
	double balance, fee, rate;

	cout << "Init these accounts: \n\n";

	cout << "Input the balance: ";
	cin >> balance;
	cout << "Input the fee for checking account: ";
	cin >> fee;
	cout << "Input the rate for savings account: ";
	cin >> rate;
	//cout << "Input the money to test debit function: ";
	//cin >> debit;
	//cout << "Input the money to test credit function: ";
	//cin >> credit;

	vector<Account*> accounts;

	Account account(balance);
	SavingsAccount savingsAccount(balance, rate);
	CheckingAccount checkingAccount(balance, fee);

	accounts.push_back(&account);
	accounts.push_back(&savingsAccount);
	accounts.push_back(&checkingAccount);

	for (size_t i = 0; i < accounts.size(); i++)
	{
		accountHandle(accounts[i]);
	}

	cout << "\n\n";

	for (size_t i = 0; i < accounts.size(); i++)
	{
		display(accounts[i]);
	}

	//cout << "The balance of a normal account: " << account.getBalance() << "." << endl;
	//account.credit(credit);
	//cout << "When it get the credit, the balance is: " << account.getBalance() << '.' << endl;
	//account.debit(debit);
	//cout << "When it withdraw the debit, the balance is: " << account.getBalance() << '.' << endl;


	//cout << "The balance of a savings account: " << savingsAccount.getBalance() << "." << endl;
	//savingsAccount.credit(credit);
	//cout << "When it get the credit, the balance is: " << savingsAccount.getBalance() << '.' << endl;
	//savingsAccount.debit(debit);
	//cout << "The final interest the savings account will get is: " << savingsAccount.calculateInterest() << "." << endl;
	//cout << "When it withdraw the debit, the balance is: " << savingsAccount.getBalance() << '.' << endl;


	//cout << "The balance of a checking account: " << checkingAccount.getBalance() << "." << endl;
	//checkingAccount.credit(credit);
	//cout << "When it get the credit, the balance is: " << checkingAccount.getBalance() << '.' << endl;
	//checkingAccount.debit(debit);
	//cout << "When it withdraw the debit, the balance is: " << checkingAccount.getBalance() << '.' << endl;


	system("pause");

}

void accountHandle(Account * account)
{
	cout << "For Type " << typeid(*account).name() << endl;
	cout << "How much do you want to withdraw: ";
	double debit;
	cin >> debit;
	account->debit(debit);
	cout << "How much do you want to credit: ";
	double credit;
	cin >> credit;
	account->credit(credit);
	SavingsAccount *savingsAccount = dynamic_cast<SavingsAccount*>(account);
	if (savingsAccount != NULL)
	{
		account->credit(savingsAccount->calculateInterest());
	}
}

void display(Account * account)
{
	cout << typeid(*account).name() << ": " << account->getBalance() << endl;
}
