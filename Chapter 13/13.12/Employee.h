#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Date.h"

using std::string;

class Employee
{
public:
	Employee(const string &, const string &, const string &, Date&);
	void setFirstName(const string&);
	string getFirstName() const;

	void setLastName(const string&);
	string getLastName() const;

	void setSocialSecurityNumber(const string &);
	string getSocialSecurityNumber() const;

	Date getBirthday() const;

	int getThisMonth() const;

	virtual double earnings() const = 0;
	virtual void print();

private:
	string firstName;
	string lastName;
	string socialSecurityNumber;
	Date birthday;
};

#endif // !EMPLOYEE_H
