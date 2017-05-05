#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H

#include "Package.h"
class TwoDayPackage : public Package
{
public:
	TwoDayPackage(senderInfo, recipientInfo, double, double, double);
	virtual double calculateCost();
private:
	double flatFee;
};

#endif // !TWODAYPACKAGE_H


