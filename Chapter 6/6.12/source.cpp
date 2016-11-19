#include <iostream>
#include <vector>
#include <iterator>
#include <iomanip>

using namespace std;

class Car
{
private:
    double hours;
    int id;
public:
    Car(int i, double h)
    {
        hours = h;
        id = i;
    }
    double getHours()
    {
        return hours;
    }
    double getId()
    {
        return id;
    }
    double calculateCharges()
    {
        if (this->hours <= 3.0)
        {
            return 2.0;
        }
        else if (this->hours > 3.0 && this->hours <= 19)
        {
            return 2.0 + (this->hours - 3.0) * 0.5;
        }
        else
        {
            return 10.0;
        }
    }
};

int main()
{
    vector<Car> Cars;
    int id = 1;
    while (1)
    {
        cout << "Please input the hours for Car " << id << " (Ctrl + Z or Ctrl + D to quit input): ";
        double hours;
        if (cin >> hours)
        {
            Car newCar(id, hours);
            Cars.push_back(newCar);
            id++;
        }
        else
        {
            break;
        }
    }
    double totalCharge = 0, totalHours = 0;
    cout << "Car\tHours\tCharge\t" << endl;

    vector<Car>::iterator iter = Cars.begin();
    while (iter != Cars.end())
    {
        double thisHours = (*iter).getHours();
        double thisCharge = (*iter).calculateCharges();
        cout << (*iter).getId() << "\t" << fixed << setprecision(1) << thisHours << "\t" << fixed << setprecision(2) << thisCharge << endl;
        totalCharge += thisCharge;
        totalHours += thisHours;
        iter++;
    }
    cout << "TOTAL\t" << fixed << setprecision(1) << totalHours << "\t" << fixed << setprecision(2) << totalCharge << endl;
    return 0;
}