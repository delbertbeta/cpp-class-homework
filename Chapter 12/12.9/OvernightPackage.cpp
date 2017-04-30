#include "OvernightPackage.h"

#include <iostream>
#include <stdexcept>

using namespace std;


OvernightPackage::OvernightPackage(senderInfo s, recipientInfo r, double w, double c, double f) : Package(s, r, w, c)
{
	if (f > 0)
	{
		additionalFee = f;
	}
	else
	{
		throw invalid_argument("Additional fee must be positive values");
	}
}

double OvernightPackage::calculateCost()
{
	return (costPerOunce + additionalFee) * weight;
}
