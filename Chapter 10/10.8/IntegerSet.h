#ifndef INTEGERSET_H
#define INTEGERSET_H

#include <vector>

class IntegerSet
{
public:
	IntegerSet();
	static IntegerSet unionOfSets(const IntegerSet& setOne, const IntegerSet& setTwo);
	static IntegerSet intersectionOfSets(const IntegerSet& setOne, const IntegerSet& setTwo);
	void insertElement(const int& index);
	void deleteElement(const int& index);
	void printSet();
	bool isEqualTo(const IntegerSet& setOne);
	std::vector<bool> set;
};

#endif
