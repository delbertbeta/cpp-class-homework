#include <iostream>

using namespace std;

int getSeat(bool seats[], int startPoint, int endPoint);

int main()
{
    bool seats[10];
    for (int i = 0; i < 10; i++)
    {
        seats[i] = false;
    }
    while (true)
    {
        cout << "Please type 1 for \"First Class\"" << endl;
        cout << "Please type 2 for \"Economy\"" << endl;
        int choice;
        cout << "Choose one: ";
        cin >> choice;
        if (choice == 1)
        {
            int seat = getSeat(seats, 0, 4);
            if (seat != -1)
            {
                cout << "Your boarding pass is " << seat + 1 << ", First Class Section.\n" << endl;
            }
            else
            {
                cout << "There is no seat available in First Class. Would you like a seat in economy section(y/n)? ";
                char choice;
                cin >> choice;
                if (choice == 'y')
                {
                    int seat = getSeat(seats, 5, 9);
                    if (seat != -1)
                    {
                        cout << "Your boarding pass is " << seat + 1 << ", Economy Section.\n" << endl;
                    }
                    else
                    {
                        cout << "There is no seats available now. Next flight leaves in 3 hours.\n" << endl;
                    }
                }
                else 
                {
                    cout << "Next flight leaves in 3 hours.\n" << endl;
                }
            }
        }else if(choice == 2)
        {
            int seat = getSeat(seats, 5, 9);
            if (seat != -1)
            {
                cout << "Your boarding pass is " << seat + 1 << ", Economy Section.\n" << endl;
            }
            else
            {
                cout << "There is no seat available in Economy Section. Would you like a seat in First Class Section(y/n)? ";
                char choice;
                cin >> choice;
                if (choice == 'y')
                {
                    int seat = getSeat(seats, 0, 4);
                    if (seat != -1)
                    {
                        cout << "Your boarding pass is " << seat + 1 << ", First Class Section.\n" << endl;
                    }
                    else
                    {
                        cout << "There is no seats available now. Next flight leaves in 3 hours.\n" << endl;
                    }
                }
                else 
                {
                    cout << "Next flight leaves in 3 hours.\n" << endl;
                }
            }
        }
        
    }
    return 0;
}

int getSeat(bool seats[], int startPoint, int endPoint)
{
    int i = startPoint;
    while (i <= endPoint)
    {
        if (seats[i] == false)
        {
            break;
        }
        else
        {
            i++;
        }
    }
    if (i == endPoint + 1)
    {
        return -1;
    }
    else
    {
        seats[i] = true;
        return i;
    }
}