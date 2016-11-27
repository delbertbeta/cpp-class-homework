#include <iostream>

using namespace std;

void hanoi(int number, char peg1, char peg2, char peg3);

int main()
{
    cout << "Please input the number of disks: ";
    int disks;
    cin >> disks;
    hanoi(disks, 'A', 'B', 'C');
    return 0;
}

void hanoi(int number, char peg1, char peg2, char peg3)
{
    if (number >= 1)
    {
        hanoi(number - 1, peg1, peg3, peg2);
        cout << peg1 << " -> " << peg3 << endl;
        hanoi(number - 1, peg2, peg1, peg3);
    }
    return;
}
