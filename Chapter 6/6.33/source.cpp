#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int flip();

int main()
{
    int heads = 0, tails = 0;
    for (int i = 1; i <= 100; i++)
    {
        cout << "Flip " << i << ": ";
        if (flip() == 1)
        {
            cout << "Heads" << endl;
            heads++;
        }
        else
        {
            cout << "Tails" << endl;
            tails++;
        }
    }
    cout << heads << " heads and " << tails << " tails in total." << endl;
    return 0;

}

int flip()
{
    srand(clock());
    return rand() % 2;
}