#include <iostream>
#include "IntegerSet.h"

using namespace std;

int main()
{
	IntegerSet is1, is2;
	is1.insertElement(1);
	is1.insertElement(2);
	is2.insertElement(2);
	is2.insertElement(3);
	cout << "Integer Set 1: ";
	is1.printSet();
	cout << endl;
	cout << "Integer Set 2: ";
	is2.printSet();
	cout << endl;
	IntegerSet us = IntegerSet::unionOfSets(is1, is2);
	cout << "Unioned Set us: ";
	us.printSet();
	cout << endl;
	IntegerSet iss = IntegerSet::intersectionOfSets(is1, is2);
	cout << "Intersection Set iss: ";
	iss.printSet();
	cout << endl;
	cout << "IS1 is equal to IS2: " << (is1.isEqualTo(is2) ? "true" : "false") << endl;
	// system("pause");
	return 0;
}