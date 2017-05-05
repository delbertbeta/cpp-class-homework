#include "BasePlusCommissionEmployee.h"
#include <iostream>
#include <stdexcept>

using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string &first, const string &last, const string &ssn, Date& birth, double sales, double rate, double salary) : CommissionEmployee(first, last, ssn, birth, sales, rate)
{
	setBaseSalary(salary);
}

void BasePlusCommissionEmployee::setBaseSalary(double salary)
{
	if (salary >= 0.0)
	{
		baseSalary = salary;
	}
	else
	{
		throw invalid_argument("Salary must be >= 0.0");
	}
}

double BasePlusCommissionEmployee::getBaseSalary() const
{
	return baseSalary;
}

double BasePlusCommissionEmployee::earnings() const
{
	double salary = getBaseSalary() + CommissionEmployee::earnings();
	if (Employee::getThisMonth() == getBirthday().getMonth())
	{
		salary += 100;
	}
	return salary;
}

void BasePlusCommissionEmployee::print()
{
	cout << "base-salaryied ";
	CommissionEmployee::print();
	cout << "; base salary: " << getBaseSalary();
}
