#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "FileManager.h"
#include "HardwareData.h"

using namespace std;

void showFunctionList();
void showTheList(fstream&);
void addItem(fstream&);
void editItem(fstream&);
void deleteItem(fstream&);

int main()
{
	fstream outFile("hardware.dat", ios::out | ios::binary | ios::in);


	if (!outFile)
	{
		cerr << "File could not be opened." << endl;
		exit(1);
	}
	else
	{
		// to determine whether the file is just created and initialize it.
		outFile.seekg(0, ios::end);
		if ((int)(outFile.tellg()) == 0)
		{
			FileManager::initialize(outFile);
		}
	}

	cout << "Welcome to hardware inventory manager." << endl;

	showFunctionList();
	int function;
	cin >> function;
	while (function != 0)
	{
		switch (function)
		{
		case 0:
			return 0;
			break;
		case 1:
			showTheList(outFile);
			break;
		case 2:
			editItem(outFile);
			break;
		case 3:
			deleteItem(outFile);
			break;
		case 4:
			addItem(outFile);
			break;
		default:
			cout << "No such function, please retry." << endl;
		}

		showFunctionList();
		cin >> function;
	}
}

void showFunctionList()
{
	cout << "\nChoose a function to continue:\n1. List all hardware.\n2. Edit one item in the list.\n3. Delete one item in the list.\n4. Add one item to the list.\nInput(0 for exit): ";
}

void showTheList(fstream& fs)
{
	cout << left << setw(10) << "Record" << setw(32) << "Tool Name" << setw(10) << "Quantity" << setw(10) << "Cost" << endl;
	for (int i = 1; i <= 100; i++)
	{
		HardwareData hardwareData = FileManager::read(fs, i);
		if (hardwareData.getRecord() != 0)
		{
			cout << left << setw(10) << hardwareData.getRecord() << setw(32) << hardwareData.getName() << setw(10) << hardwareData.getQuantity() << setw(10) << hardwareData.getCost() << endl;
		}
	}
}

void addItem(fstream & fs)
{
	int recordId;
	int quantity;
	double cost;
	string name;


	cout << "Please input the record id(input 0 for auto-increment record id): ";
	cin >> recordId;
	if (recordId == 0)
	{
		for (int i = 0; i < 100; i++)
		{
			HardwareData hardwareData = FileManager::read(fs, i);
			if (hardwareData.getRecord() == 0)
			{
				recordId = hardwareData.getRecord();
				cout << "The new record id is " << recordId << "." << endl;
			}
		}
	}
	else
	{
		if (FileManager::read(fs, recordId).getRecord() != 0)
		{
			cout << "The record is already exists, do you want to override it (y/n)? ";
			char choose;
			cin >> choose;
			if (choose != 'y')
			{
				return;
			}
		}
	}
	cout << "Name: ";
	cin.clear();
	cin.ignore();
	getline(cin, name);

	cout << "Quantity: ";
	cin >> quantity;

	cout << "Cost: ";
	cin >> cost;

	HardwareData hardwareData(recordId, name, quantity, cost);
	FileManager::write(fs, hardwareData, recordId);
	cout << "Add successfully." << endl;
}

void editItem(fstream & fs)
{
	int recordId;
	int quantity;
	double cost;
	string name;


	cout << "Please input the record id of the item to edit: ";
	cin >> recordId;

	HardwareData oldData = FileManager::read(fs, recordId);
	if (oldData.getRecord() == 0)
	{
		cout << "No such item!" << endl;
		return;
	}
	cout << "Please input the new information of this item.(Input 0 to keep the original data)" << endl;
	cout << "New record id: ";

	cin >> recordId;
	recordId = recordId == 0 ? oldData.getRecord() : recordId;
	if (recordId != oldData.getRecord())
	{
		if (FileManager::read(fs, recordId).getRecord() != 0)
		{
			cout << "The record is already exists, do you want to override it (y/n)? ";
			char choose;
			cin >> choose;
			if (choose != 'y')
			{
				return;
			}
		}
	}
	cout << "New name: ";
	cin.clear();
	cin.ignore();
	getline(cin, name);
	name = name == "0" ? oldData.getName() : name;

	cout << "New quantity: ";
	cin >> quantity;
	quantity = quantity == 0 ? oldData.getQuantity() : quantity;

	cout << "New cost: ";
	cin >> cost;
	cost = cost == 0.0 ? oldData.getCost() : cost;

	HardwareData newData(recordId, name, quantity, cost);
	FileManager::write(fs, newData, recordId);
	cout << "Edit successfully." << endl;
}

void deleteItem(fstream &fs)
{
	cout << "Which item do you want to delete: " << endl;
	int recordId;
	cin >> recordId;
	HardwareData hardwareData;
	FileManager::write(fs, hardwareData, recordId);
	cout << "Delete successfully." << endl;
}
