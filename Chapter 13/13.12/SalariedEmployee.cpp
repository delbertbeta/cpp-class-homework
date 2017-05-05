#include "SalariedEmployee.h"

#include <iostream>
#include <stdexcept>

using namespace std;

SalariedEmployee::SalariedEmployee(const string &first, const string &last, const string &ssn, Date& birth, double salary) : Employee(first, last, ssn, birth)
{
	setWeeklySalary(salary);
}

void SalariedEmployee::setWeeklySalary(double salary)
{
	if (salary >= 0.0)
	{
		weeklySalary = salary;
	}
	else
	{
		throw invalid_argument("Weekly salary must be >= 0.0");
	}
}

double SalariedEmployee::getWeeklySalary() const
{
	double salary = weeklySalary;
	if (Employee::getThisMonth() == getBirthday().getMonth())
	{
		salary += 100;
	}
	return salary;
}

double SalariedEmployee::earnings() const
{
	return getWeeklySalary();
}

void SalariedEmployee::print()
{
	cout << "salaried employee: ";
	Employee::print();
	cout << "\nweekly salary: " << getWeeklySalary();
}
