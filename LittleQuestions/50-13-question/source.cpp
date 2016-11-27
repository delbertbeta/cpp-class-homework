#include <iostream>

using namespace std;

int main()
{
	int packages[1000];
	int pointer = -1;
	int total, where;
	cin >> total >> where;

	//initialize the packages
	for (int i = 0; i < 1000; i++)
	{
		packages[i] = 1;
	}

	for (int i = 1; i <= total; i++)
	{
		int counter = 1;
		while (counter <= where)
		{
			counter += packages[++pointer];
			if (pointer == total)
			{
				pointer = 0;
			}
		}
		if (i == total)
		{
			cout << "\nThe Last One is " << pointer + 1 << endl;
		}
		else
		{
			packages[pointer] == 0;
			cout << pointer + 1 << "\t";
		}
	}
	system("pause");
	return 0;
}