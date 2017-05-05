#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H

#include "Package.h"
class OvernightPackage : public Package
{
public:
	OvernightPackage(senderInfo, recipientInfo, double, double, double);
	virtual double calculateCost();

private:
	double additionalFee;
};


#endif // !OVERNIGHTPACKAGE_H
