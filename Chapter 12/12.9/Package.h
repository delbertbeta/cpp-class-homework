#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

using std::string;

struct senderInfo
{
	string name;
	string address;
	string city;
	string state;
	string zipCode;
};
struct recipientInfo
{
	string name;
	string address;
	string city;
	string state;
	string zipCode;
};

class Package
{
public:
	Package(senderInfo, recipientInfo, double, double);
	double calculateCost();

protected:
	senderInfo sender;
	recipientInfo recipient;
	double weight;
	double costPerOunce;

};

#endif // !PACKAGE_H
