#include <iostream>

using namespace std;

int main()
{
    int counter = 1;
    double number, largest;
    cout << "Please input 10 numbers: ";
    while (counter <= 10)
    {
        cin >> number;
        if (counter == 1)
        {
            largest = number;
        }
        else
        {
            if (number > largest)
            {
                largest = number;
            }
        }
        counter++;
    }
    cout << "The largest number is: " << largest << endl;
    return 0;
}