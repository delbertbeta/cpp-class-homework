#include <iostream>

using namespace std;

int main()
{
	cout << "interger\tsquare\tcube\t" << endl;
	for (int i = 0; i <= 10; i++)
	{
		printf("%d\t%d\t%d\n", i, i * i, i * i * i);
	}
	return 0;
}
