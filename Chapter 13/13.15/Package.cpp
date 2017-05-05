#include "Package.h"

#include <iostream>
#include <stdexcept>

using namespace std;

Package::Package(senderInfo s, recipientInfo r, double w, double c)
{
	sender = s;
	recipient = r;
	if (w > 0 && c > 0)
	{
		weight = w;
		costPerOunce = c;
	}
	else
	{
		throw invalid_argument("Weight and cost per ounce must be positive values");
	}

}

double Package::calculateCost()
{
	return weight * costPerOunce;
}

string Package::getSenderInfo() const
{
	return "Sender address: " + sender.address;
}

string Package::getRecipientInfo() const
{
	return "Recipient address: " + recipient.address;
}
