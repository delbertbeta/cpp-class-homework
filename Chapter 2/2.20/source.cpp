#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double radius;
	cout << "Input the radius of a circle: ";
	if (cin >> radius)
	{
		const double _Pi = 3.14159;
		cout << "Diameter is " << radius * 2 << endl;
		cout << "Circumference is " << radius * 2 * _Pi << endl;
		cout << "Area is " << pow(radius,2) * _Pi << endl;
	}
	else
	{
		cout << "The numbers are invaild." << endl;
	}
	return 0;
}