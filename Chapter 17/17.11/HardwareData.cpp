#include "HardwareData.h"
#include <stdexcept>

using namespace std;

HardwareData::HardwareData(int record, string name, int quantity, double cost)
{
	setRecord(record);
	setName(name);
	setQuantity(quantity);
	setCost(cost);
}

void HardwareData::setRecord(int r)
{
	if (r >= 0 && r <= 100)
	{
		record = r;
	}
	else
	{
		throw invalid_argument("Record id must be >= 0 and <= 100");
	}
}

int HardwareData::getRecord() const
{
	return record;
}

void HardwareData::setName(string n)
{
	int length = n.size();
	length = length < 31 ? length : 30;
	n.copy(name, length);
	name[length] = '\0';
}

string HardwareData::getName() const
{
	return name;
}

void HardwareData::setQuantity(int q)
{
	if (q >= 0)
	{
		quantity = q;
	}
	else
	{
		throw invalid_argument("Quantity must be >= 0");
	}
}

int HardwareData::getQuantity() const
{
	return quantity;
}

void HardwareData::setCost(double c)
{
	if (c >= 0)
	{
		cost = c;
	}
	else
	{
		throw invalid_argument("Cost musb be >= 0");
	}
}

double HardwareData::getCost() const
{
	return cost;
}
