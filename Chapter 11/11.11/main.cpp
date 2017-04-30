#include <iostream>
#include "Polynomial.h"

using namespace std;

int main()
{
	Polynomial p1;
	Polynomial p2;
	cout << "p1 + p2 = " << p1 + p2 << endl;
	cout << "p1 - p2 = " << p1 - p2 << endl;
	cout << "p1 * p2 = " << p1 * p2 << endl;
	p1 += p2;
	cout << "p1 += p2, p1 = " << p1 << endl;
	p1 -= p2;
	cout << "p1 -= p2, p1 =" << p1 << endl;
	p1 = p2;
	cout << "p1 = p2, p1 =" << p1 << endl;
	system("pause");
}