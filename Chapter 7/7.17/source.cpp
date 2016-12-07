#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(clock());
    int results[13];
    for (int i = 0; i < 13; i++)
    {
        results[i] = 0;
    }
    for (int i = 1; i <= 36000; i++)
    {
        int firstDice = (rand() % 6) + 1;
        int secondDice = (rand() % 6) + 1;
        int sum = firstDice + secondDice;
        results[sum]++;
    }
    cout << "Sum\t";
    for (int i = 2; i <= 12; i++)
    {
        cout << i << "\t";
    }
    cout << endl << "Times\t";
    for (int i = 2; i <= 12; i++)
    {
        cout << results[i] << "\t";
    }
    cout << endl;
    return 0;
}
