#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "Assume that x = 2 and y = 7" << endl;
	int x = 2, y = 7;
	cout << "The result of !(x < 5) && !(y >= 7) is " << boolalpha << (!(x < 5) && !(y >= 7)) << endl;
	cout << "The result of !(x < 5 && y >= 7) is " << boolalpha << !(x < 5 && y >= 7) << endl << endl;

	cout << "Assume that a = 2, b = 7 and g = 5" << endl;
	int a = 2, b = 7, g = 5;
	cout << "The result of !(a == b) || !(g != 5) is " << boolalpha << (!(a == b) || !(g != 5)) << endl;
	cout << "The result of !((a == b) || (g != 5)) is " << boolalpha << (!((a == b) || (g != 5))) << endl << endl;

	cout << "Assume that x = 2 and y = 7" << endl;
	cout << "The result of !(a <= 8 && y > 4) is " << boolalpha << (!(a <= 8 && y > 4)) << endl;
	cout << "The result of !(a <= 8) && !(y > 4) is " << boolalpha << (!(a <= 8) && !(y > 4)) << endl << endl;

	cout << "Assume that i = 2 and j = 7" << endl;
	int i = 2, j = 7;
	cout << "The result of !(i > 4 || j <= 6) is " << boolalpha << (!(i > 4 || j <= 6)) << endl;
	cout << "The result of !(i > 4) || !(j <= 6) is " << boolalpha << (!(i > 4) || !(j <= 6)) << endl;

	return 0;
}
