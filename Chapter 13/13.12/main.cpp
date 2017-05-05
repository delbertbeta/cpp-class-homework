#include <iostream>
#include <iomanip>
#include <vector>

#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

using namespace std;

void virtualViaPointer(Employee * const);
void virtualViaReference(Employee &);

int main()
{
	cout << fixed << setprecision(2);

	Date salariedEmployeeBirthday(3, 9, 1998);
	SalariedEmployee salariedEmployee("John", "Smith", "111-11-1111", salariedEmployeeBirthday, 800);
	Date commissionEmployeeBirthday(4, 9, 1998);
	CommissionEmployee commissionEmployee("Sue", "Jones", "333-33-3333", commissionEmployeeBirthday, 10000, 0.06);
	Date basePlusCommissionEmployeeBirthday(5, 9, 1998);
	BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "444-44-4444", basePlusCommissionEmployeeBirthday, 5000, 0.04, 300);

	cout << "Employees processed individually using static binding: \n\n";

	salariedEmployee.print();
	cout << "\nearned $" << salariedEmployee.earnings() << "\n\n";
	commissionEmployee.print();
	cout << "\nearned $" << commissionEmployee.earnings() << "\n\n";
	basePlusCommissionEmployee.print();
	cout << "\nearned $" << basePlusCommissionEmployee.earnings() << "\n\n";

	vector <Employee*> employees(3);

	employees[0] = &salariedEmployee;
	employees[1] = &commissionEmployee;
	employees[2] = &basePlusCommissionEmployee;

	cout << "Employees processed polymorphically via dynamic binding:\n\n";

	cout << "Virtual function calls made off base-class pointers:\n\n";

	for (size_t i = 0; i < employees.size(); ++i)
	{
		virtualViaPointer(employees[i]);
	}

	cout << "Virtual function calls made off base-class references:\n\n";

	for (size_t i = 0; i < employees.size(); ++i)
	{
		virtualViaReference(*employees[i]);
	}

	system("pause");

}

void virtualViaPointer(Employee* const baseClassPtr)
{
	baseClassPtr->print();
	cout << "\nearned $" << baseClassPtr->earnings() << "\n\n";
}

void virtualViaReference(Employee &baseClassRef)
{
	baseClassRef.print();
	cout << "\nearned $" << baseClassRef.earnings() << "\n\n";
}