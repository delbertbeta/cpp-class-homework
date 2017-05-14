#pragma once
#include <string>
using std::string;
class HardwareData
{
public:
	HardwareData(int record = 0, string name = "", int quantity = 0, double cost = 0.0);
	
	void setRecord(int);
	int getRecord() const;
	
	void setName(string);
	string getName() const;
	
	void setQuantity(int);
	int getQuantity() const;

	void setCost(double);
	double getCost() const;
private:
	int record;
	char name[31];
	int quantity;
	double cost;
};

