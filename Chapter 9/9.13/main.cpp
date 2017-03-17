#include <iostream>
#include "Rectangle.h"

using namespace std;

int main()
{
    double coordinates[4][2];
    for (int i = 0; i < 4; i++)
    {
        cout << "Please input the point (" << i + 1 << "/4): ";
        for (int j = 0; j < 2; j++)
        {
            cin >> coordinates[i][j];
        }
    }
	Rectangle rec(coordinates);
	cout << "Length: " << rec.length() << endl; 
    cout << "Width: " << rec.width() << endl;
	cout << "Perimeter: " << rec.perimeter() << endl;
	cout << "Area: " << rec.area() << endl; 
    cout << "Is Square: " << (rec.square() ? "Yes" : "No") << endl;
    cout << "Input the perimeter character(#): ";
    char p;
    cin >> p;
    char f;
    cout << "Input the fill character(*): ";
    cin >> f;
    rec.setPerimeterCharacter(p);
    rec.setFillCharacter(f);
    rec.draw();
	// system("pause");
	return 0;
}