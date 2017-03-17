#include <iostream>
#include <cmath>
#include "HugeInteger.h"

using namespace std;

HugeInteger::HugeInteger()
{
	for (int i = 0; i < 40; i++)
	{
		hugeInteger[i] = -999;
	}
}

void HugeInteger::input()
{
	int counter = 0;
	char temp[40];
	for (int i = 0; i < 40; i++)
	{
		if (cin >> temp[i])
		{
			if (temp[i] >= 48 && temp[i] <= 57)
			{
				counter++;
			}
			else
			{
				break;
			}
		}
		else {
			break;
		}
	}
	cin.clear();
	int index = 0;
	for (int i = 40 - counter; i < 40; i++)
	{
		hugeInteger[i] = temp[index++] - 48;
	}
	index = 40 - counter;
	while (index < 40 && hugeInteger[index] == 0)
	{
		counter--;
		hugeInteger[index] = -999;
		index++;
	}
	length = counter;
}

void HugeInteger::output()
{
	for (int i = 40 - length; i < 40; i++)
	{
		cout << hugeInteger[i];
	}
}

void HugeInteger::add(const HugeInteger& hi)
{
	int index = 39;
	while (index > 0 && hi.hugeInteger[index] != -999)
	{
		if (hugeInteger[index] == -999)
		{
			hugeInteger[index] = 0;
		}
		hugeInteger[index] += hi.hugeInteger[index];
		index--;
	}
	index = 39;
	int counter = 0;
	while (index > 0 && hugeInteger[index] != -999)
	{
		counter++;
		if (hugeInteger[index] >= 10)
		{
			hugeInteger[index] = hugeInteger[index] % 10;
			if (hugeInteger[index - 1] == -999)
			{
				hugeInteger[index - 1] = 1;
			}
			else {
				hugeInteger[index - 1]++;
			}
		}
		index--;
	}
	length = counter;
}

bool HugeInteger::isEqualTo(const HugeInteger& hi)
{
	if (length != hi.length)
	{
		return false;
	}
	for (int i = 39; i >= 40 - length; i--)
	{
		if (hi.hugeInteger[i] != hugeInteger[i])
		{
			return false;
		}
	}
	return true;
}

bool HugeInteger::isNotEqualTo(const HugeInteger& hi)
{
	return !isEqualTo(hi);
}

bool HugeInteger::isGreaterThan(const HugeInteger& hi)
{
	if (length > hi.length)
	{
		return true;
	}
	else if (length < hi.length)
	{
		return false;
	}
	else
	{
		for (int i = 40 - length; i < 40; i++)
		{
			if (hi.hugeInteger[i] > hugeInteger[i])
			{
				return false;
			}
			if (hi.hugeInteger[i] == hugeInteger[i])
			{
				continue;
			}
			if (hi.hugeInteger[i] < hugeInteger[i])
			{
				return true;
			}
		}
	}
	return false;
}

bool HugeInteger::isGreaterThanOrEqualTo(const HugeInteger& hi)
{
	return (isGreaterThan(hi) || isEqualTo(hi));
}

bool HugeInteger::isLessThan(const HugeInteger& hi)
{
	return !(isGreaterThanOrEqualTo(hi));
}

bool HugeInteger::isLessThanOrEqualTo(const HugeInteger& hi)
{
	return !(isGreaterThan(hi));
}


void HugeInteger::subtract(const HugeInteger& hi)
{
	if (isGreaterThanOrEqualTo(hi))
	{
		int index = 39;
		while (index > 0 && hi.hugeInteger[index] != -999)
		{
			if (hugeInteger[index] - hi.hugeInteger[index] >= 0)
			{
				hugeInteger[index] -= hi.hugeInteger[index];
			}
			else {
				hugeInteger[index] = hugeInteger[index] - hi.hugeInteger[index] + 10;
				hugeInteger[index - 1]--;
			}
			index--;
		}
		//index = 39;
		//while (index > 0 && hugeInteger[index] != -999)
		//{
		//	if (hugeInteger[index] < 0)
		//	{
		//		hugeInteger[index] = abs(hugeInteger[index]) % 10;
		//		hugeInteger[index - 1]--;
		//	}
		//	index--;
		//}
		index = 0;
		while (index < 40 && (hugeInteger[index] == 0 || hugeInteger[index] == -999))
		{
			if (hugeInteger[index] = 0)
			{
				hugeInteger[index] = -999;
			}
			index++;
		}
		length = 40 - index;
	}
	else
	{
		cout << "Negative number is not allowed!";
	}
}