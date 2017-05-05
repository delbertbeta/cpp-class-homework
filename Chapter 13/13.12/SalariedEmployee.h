#ifndef SLARIED_H
#define SLARIED_H


#include "Employee.h"


class SalariedEmployee : public Employee
{
public:
	SalariedEmployee(const string &, const string &, const string &, Date& , double = 0.0);

	void setWeeklySalary(double);
	double getWeeklySalary() const;

	virtual double earnings() const;
	virtual void print();

private:
	double weeklySalary;
};


#endif // !SLARIED_H
