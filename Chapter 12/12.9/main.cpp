#include "Package.h"
#include "OvernightPackage.h"
#include "TwoDayPackage.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "The infomation defination is in the codes." << endl;
	senderInfo sender;
	sender.name = "Delbert";
	sender.city = "GuangZhou";
	sender.state = "GuangDong";
	sender.address = "SCUT, HEMC";
	sender.zipCode = "510006";
	recipientInfo recipient;
	recipient.name = "Sagiri";
	sender.city = "Tokyo";
	sender.state = "Japan";
	sender.address = "Izumi's House";
	sender.zipCode = "163-8001";
	double weight = 2.0;
	double costPerOunce = 3.0;
	double flatFee = 1.0;
	double additionalFee = 2.2;
	Package package(sender, recipient, weight, costPerOunce);
	TwoDayPackage twoDayPackage(sender, recipient, weight, costPerOunce, flatFee);
	OvernightPackage overnightPackage(sender, recipient, weight, costPerOunce, additionalFee);
	cout << "If this is a normal package, the cost is " << package.calculateCost() << "." << endl;
	cout << "If this is a two day package, the cost is " << twoDayPackage.calculateCost() << "." << endl;
	cout << "If this is a overnight package, the cost is " << overnightPackage.calculateCost() << "." << endl;
	system("pause");
}