#include <iostream>
#include "Rectangle.h"

using namespace std;

int main()
{
    double length, width;
    cout << "Please input the length and width of a rectangle: ";
    cin >> length >> width;
    Rectangle r(length, width);
    cout << "It's area is: " << r.area() << ". It's perimeter is: " << r.perimeter() << "." << endl;
    return 0;
}