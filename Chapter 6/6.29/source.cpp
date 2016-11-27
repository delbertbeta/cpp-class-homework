#include <iostream>
#include <ctime>

using namespace std;

bool isPrimeNumberWithHalfUpper(int number);
bool isPrimeNumberWithFullUpper(int number);

int main()
{
    cout << "Using isPrimeNumberWithHalfUpper(int number):" << endl;
    double startTime = (double)clock();
    for (int i = 2; i <= 10000; i++)
    {
        if (isPrimeNumberWithHalfUpper(i))
        {
            cout << i << "\t";
        }
    }
    double finishTime = (double)clock();
    cout << "\nIt costs " << (finishTime - startTime) / CLOCKS_PER_SEC << " seconds to execute." << endl;


    startTime = (double)clock();
    cout << "Using isPrimeNumberWithFullUpper(int number):" << endl;
    for (int i = 2; i <= 10000; i++)
    {
        if (isPrimeNumberWithFullUpper(i))
        {
            cout << i << "\t";
        }
    }
    finishTime = (double)clock();
    cout << "\nIt costs " << (finishTime - startTime) / CLOCKS_PER_SEC << " seconds to execute." << endl;
}

bool isPrimeNumberWithHalfUpper(int number)
{
    int upper = number / 2;
    bool isPrimeNumber = true;
    for (int i = 2; i <= upper; i++)
    {
        if (number % i == 0)
        {
            isPrimeNumber = false;
            break;
        }
    }
    return isPrimeNumber;
}

bool isPrimeNumberWithFullUpper(int number)
{
    bool isPrimeNumber = true;
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            isPrimeNumber = false;
            break;
        }
    }
    return isPrimeNumber;
}