#include <iostream>

using namespace std;

int calculateSeconds(int hours, int minutes, int seconds);

int main()
{
    cout << "Please input the time_1 (hours minutes seconds): ";
    int hours, minutes, seconds;
    cin >> hours >> minutes >> seconds;
    int seconds_1 = calculateSeconds(hours, minutes, seconds);
    cout << "Please input the time_2 (hours minutes seconds): ";
    cin >> hours >> minutes >> seconds;
    int seconds_2 = calculateSeconds(hours, minutes, seconds);
    int secondsDifference = seconds_1 > seconds_2 ? seconds_1 - seconds_2 : seconds_2 - seconds_1;
    cout << "The difference between two times is " << secondsDifference << "s." << endl;
    return 0;
}

int calculateSeconds(int hours, int minutes, int seconds)
{
    return hours * 3600 + minutes * 60 + seconds;
}