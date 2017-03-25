#include "IntegerSet.h"
#include <iterator>
#include <iostream>
using std::vector;
using std::cout;

IntegerSet::IntegerSet()
{
	for (int i = 0; i < 100; i++)
	{
		set.push_back(false);
	}
}

IntegerSet IntegerSet::unionOfSets(const IntegerSet & setOne, const IntegerSet & setTwo)
{
	IntegerSet is;
	vector<bool>::const_iterator thisIter = setOne.set.begin();
	vector<bool>::const_iterator thatIter = setTwo.set.begin();
	int index = 1;
	while (thisIter != setOne.set.end())
	{
		if ((*thisIter) || (*thatIter))
		{
			is.insertElement(index);
		}
		thisIter++;
		thatIter++;
		index++;
	}
	return is;
}

IntegerSet IntegerSet::intersectionOfSets(const IntegerSet & setOne, const IntegerSet & setTwo)
{
	//return IntegerSet();
	IntegerSet is;
	vector<bool>::const_iterator thisIter = setOne.set.begin();
	vector<bool>::const_iterator thatIter = setTwo.set.begin();
	int index = 1;
	while (thisIter != setOne.set.end())
	{
		if ((*thisIter) && (*thatIter))
		{
			is.insertElement(index);
		}
		thisIter++;
		thatIter++;
		index++;
	}
	return is;
}

void IntegerSet::insertElement(const int & index)
{
	int a = index - 1;
	set[a] = true;
}

void IntegerSet::deleteElement(const int & index)
{
	int a = index - 1;
	set[a] = false;
}

void IntegerSet::printSet()
{
	vector<bool>::const_iterator thisIter = set.begin();
	int index = 1;
	while (thisIter != set.end())
	{
		if ((*thisIter) == true)
		{
			cout << index << " ";
		}
		index++;
		thisIter++;
	}
}

bool IntegerSet::isEqualTo(const IntegerSet & setOne)
{
	vector<bool>::const_iterator thisIter = set.begin();
	vector<bool>::const_iterator thatIter = setOne.set.begin();
	while (thisIter != set.end())
	{
		if ((*thisIter) != (*thatIter))
		{
			return false;
		}
		thisIter++;
		thatIter++;
	}
}
