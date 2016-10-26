#include <iostream>
#include <vector>

using namespace std;
vector<int> getDigits (int longInteger)
{
	vector<int> digits;
	int int1 = longInteger % 10;
	digits.push_back(int1);
	int int2 = (longInteger % 100 - int1) / 10;
	digits.push_back(int2);
	int int3 = (longInteger % 1000 - int1 - 10 * int2) / 100;
	digits.push_back(int3);
	int int4 = (longInteger % 10000 - int1 - 10 * int2 - 100 * int3) / 1000;
	digits.push_back(int4);
	int int5 = (longInteger - int1 - 10 * int2 - 100 * int3 - 1000 * int4) / 10000;
	digits.push_back(int5);
	return digits;
}

int main()
{
	cout << "Please input a five-digit integer: ";
	int a;
	if (cin >> a)
	{
		vector<int> digits  = getDigits(a);
		for (int i = 4; i >= 0; i--)
		{
			cout << digits[i] << "\t";
		}
		cout << endl;
	}
	else
	{
		cout << "The number is invaild." << endl;
	}
	return 0;
}
