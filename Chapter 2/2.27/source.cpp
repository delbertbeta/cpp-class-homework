#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	char a;
	cout << "Please enter a char here: ";
	while (cin >> a)
	{
		cout << "Its integer equivalent is: " << static_cast<int>(a) << endl;
		cout << "Please enter a char here: ";
	}
	return 0;
}