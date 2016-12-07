#include <iostream>

using namespace std;

void findPrimeNumber(bool primeNumber[]);

int main()
{
    bool primeNumbers[1000];
    for (int i = 0; i <= 999; i++)
    {
        primeNumbers[i] = true;
    }
    findPrimeNumber(primeNumbers);
    for (int i = 2; i <= 999; i++)
    {
        if (primeNumbers[i])
        {
            cout << i << "\t";
        }
    }
    cout << endl;
    return 0;
}

void findPrimeNumber(bool primeNumber[])
{
    for (int i = 2; i <= 500; i++)
    {
        for (int j = 2; j <= 500; j++)
        {
            if (i * j >= 1000)
            {
                break;
            }
            else
            {
                primeNumber[i * j] = false;
            }
        }
    }
}