#include <iostream>

using namespace std;

long computeFactorial(short n);

int main()
{
	for (int i = 1; i <= 5; i++)
	{
		cout << i << "!\t";
	}
	cout << endl;
	for (int i = 1; i <= 5; i++)
	{
		cout << computeFactorial(i) << "\t";
	}
	cout << endl;
	cout << "The answer to the question: it's too large to store the result of 20! into basic data types." << endl;
	return 0;
}

long computeFactorial(short n)
{
	if (n == 1)
		return 1;
	return n * computeFactorial(n - 1);
}