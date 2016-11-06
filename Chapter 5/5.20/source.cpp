#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	cout << "Side_1\tSide_2\tHypotenuse" << endl;
	for (int side_1 = 1; side_1 <= 500; side_1++)
	{
		for (int side_2 = 1; side_2 <= 500; side_2++)
		{
			for (int hypotenuse = 1; hypotenuse <= 500; hypotenuse++)
			{
				if (side_1 + side_2 >= hypotenuse)
				{
					if (pow(side_1, 2) + pow(side_2, 2) == pow(hypotenuse, 2))
					{
						cout << side_1 << "\t" << side_2 << "\t" << hypotenuse << endl;
					}
				}
			}
		}
	}
	return 0;
}
