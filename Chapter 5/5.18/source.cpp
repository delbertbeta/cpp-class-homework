#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "Dec\t" << "Oct\t" << "Hex" << endl;
	for (int i = 1; i <= 256; i++)
	{
		cout << dec << i << "\t" << oct << i << "\t" << hex << i << endl;
	}
	return 0;
}
