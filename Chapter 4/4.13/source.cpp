#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double totalMiles = 0, totalGallons;
	double miles, gallons;
	
	cout << "Enter miles driven (-1 to quit): ";
	cin >> miles;
	while (miles != -1)
	{
		cout << "Enter gallons used: ";
		cin >> gallons;
		totalMiles += miles;
		totalGallons += gallons;
		cout << "MPG this trip: " << fixed << setprecision(6) << miles / gallons << endl;
		cout << "Total MPG: " << fixed << setprecision(6) << totalMiles / totalGallons << endl << endl;
		cout << "Enter miles driven (-1 to quit): ";
		cin >> miles;
	}
	return 0;
}