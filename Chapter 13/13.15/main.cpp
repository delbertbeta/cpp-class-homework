#include "Package.h"
#include "OvernightPackage.h"
#include "TwoDayPackage.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void packageHandle(Package* package, double& total);

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
	recipient.city = "Tokyo";
	recipient.state = "Japan";
	recipient.address = "Izumi's House";
	recipient.zipCode = "163-8001";
	double weight = 2.0;
	double costPerOunce = 3.0;
	double flatFee = 1.0;
	double additionalFee = 2.2;
	Package package(sender, recipient, weight, costPerOunce);
	TwoDayPackage twoDayPackage(sender, recipient, weight, costPerOunce, flatFee);
	OvernightPackage overnightPackage(sender, recipient, weight, costPerOunce, additionalFee);
	vector<Package*> packages;
	packages.push_back(&package);
	packages.push_back(&twoDayPackage);
	packages.push_back(&overnightPackage);

	double total = 0.0;
	for (size_t i = 0; i < packages.size(); i++)
	{
		packageHandle(packages[i], total);
	}
	cout << "\n\nTotal cost: " << total << endl;
	system("pause");
}

void packageHandle(Package * package, double& total)
{
	total += package->calculateCost();
	cout << typeid(*package).name() << ": \n" << package->getSenderInfo() << "\n" << package->getRecipientInfo() << "\n" << "Cost: " << package->calculateCost() << "\n" << endl;
}
