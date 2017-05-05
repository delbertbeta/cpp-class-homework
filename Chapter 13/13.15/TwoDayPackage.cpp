#include "TwoDayPackage.h"

#include <iostream>
#include <stdexcept>

using namespace std;

TwoDayPackage::TwoDayPackage(senderInfo s, recipientInfo r, double w, double c, double f): Package(s, r, w, c)
{
	if (f > 0)
	{
		flatFee = f;
	}
	else
	{
		throw invalid_argument("Flat fee must be positive values");
	}
}

double TwoDayPackage::calculateCost()
{
	return Package::calculateCost() + flatFee;
}
