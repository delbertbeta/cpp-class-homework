#include "Employee.h"

#include <iostream>
#include <ctime>

using namespace std;

Employee::Employee(const string &first, const string &last, const string &ssn, Date& birth) : firstName(first), lastName(last), socialSecurityNumber(ssn), birthday(birth)
{
}

void Employee::setFirstName(const string &first)
{
	firstName = first;
}

string Employee::getFirstName() const
{
	return firstName;
}

void Employee::setLastName(const string &last)
{
	lastName = last;
}

string Employee::getLastName() const
{
	return lastName;
}

void Employee::setSocialSecurityNumber(const string &ssn)
{
	socialSecurityNumber = ssn;
}

string Employee::getSocialSecurityNumber() const
{
	return socialSecurityNumber;
}

Date Employee::getBirthday() const
{
	return birthday;
}

int Employee::getThisMonth() const
{
	struct tm *local;
	time_t lt;
	lt = time(NULL);
	local = localtime(&lt);
	return local->tm_mon + 1;
}

void Employee::print()
{
	cout << getFirstName() << ' ' << getLastName() << "\nsocial security number: " << getSocialSecurityNumber() << "\nBirthday: "
		<< birthday.getYear() << "/" << birthday.getMonth() << "/" << birthday.getDay() << "            " << ((birthday.getMonth() == getThisMonth()) ? "This month is his/her birthday!" : "");
}
