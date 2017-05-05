#include "CommissionEmployee.h"
#include <iostream>
#include <stdexcept>

using namespace std;

CommissionEmployee::CommissionEmployee(const string &first, const string &last, const string &ssn, Date& birth, double sales, double rate) : Employee(first, last, ssn, birth)
{
	setCommissionRate(rate);
	setGrossSales(sales);
}

void CommissionEmployee::setCommissionRate(double rate)
{
	if (rate > 0.0 && rate < 1.0)
	{
		commissionRate = rate;
	}
	else
	{
		throw invalid_argument("Commission rate must be > 0.0 and < 1.0");
	}
}

double CommissionEmployee::getCommissionRate() const
{
	return commissionRate;
}

void CommissionEmployee::setGrossSales(double sales)
{
	if (sales >= 0.0)
	{
		grossSales = sales;
	}
	else
	{
		throw invalid_argument("Gross sales must be >= 0.0");
	}
}

double CommissionEmployee::getGrossSales() const
{
	return grossSales;
}

double CommissionEmployee::earnings() const
{

	double salary = getCommissionRate() * getGrossSales();
	if (Employee::getThisMonth() == getBirthday().getMonth())
	{
		salary += 100;
	}
	return salary;
}

void CommissionEmployee::print()
{
	cout << "commission employee: ";
	Employee::print();
	cout << "\ngross sales: " << getGrossSales() << "; commission rate: " << getCommissionRate();
}
