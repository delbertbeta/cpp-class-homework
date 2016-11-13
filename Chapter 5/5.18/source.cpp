#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>

using namespace std;

string getBinary(int i);

int main()
{
	cout << "Bin\t" << "Dec\t" << "Oct\t" << "Hex" << endl;
	for (int i = 1; i <= 256; i++)
	{
		cout << getBinary(i) << "\t" << dec << i << "\t" << oct << i << "\t" << hex << i << endl;
	}
	return 0;
}

string getBinary(int i)
{
	vector<int> binaryVector;
	do
	{
		int digit = i % 2;
		binaryVector.push_back(digit);
		i = i / 2;
	}while(i != 0);
	vector<int>::reverse_iterator iter = binaryVector.rbegin();
	string binaryString;
	while (iter != binaryVector.rend())
	{
		binaryString += (*iter + 48);
		iter++;
	}
	return binaryString;
}
