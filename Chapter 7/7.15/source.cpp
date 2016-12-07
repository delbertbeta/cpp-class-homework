#include <iostream>

using namespace std;

int main()
{
    int numbers[20], point = 0;
    for (int count = 1; count <= 20; count++)
    {
        cout << "Please input a number(10 <= number <= 100): ";
        int number;
        cin >> number;
        while (number > 100 || number < 10)
        {
            cout << "It an invalid number(10 <= number <= 100). Please input again: "; 
            cin >> number;
        }
        if (count == 1)
        {
            numbers[point++] = number;
        }
        else
        {
            bool isDuplicate = false;
            for (int i = 0; i < point; i++)
            {
                if (number == numbers[i])
                {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate)
            {
                numbers[point++] = number;
            }
        }
    }
    cout << "The numbers that are not duplicated: ";
    for (int i = 0; i < point; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
    return 0;
}