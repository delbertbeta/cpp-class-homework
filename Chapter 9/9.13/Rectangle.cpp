#include <stdexcept>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "Rectangle.h"

using namespace std;

void swap(double& x, double& y)
{
    if (x > y)
    {
        int temp = x;
        x = y;
        y = temp;
    }
}

Rectangle::Rectangle(double coordinates[4][2])
{
	for (int i = 0; i <= 3; i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			if (coordinates[i][j] > 20 && coordinates[i][j] < 0)
			{
				throw invalid_argument("Coordinate must between 0-20.");
			}
		}
	}

    double tX1, tX2, tY1, tY2;

	int counter = 1;
	double first = coordinates[0][0];
	tX1 = coordinates[0][0];
	for (int i = 1; i <= 3; i++)
	{
		if (coordinates[i][0] == first)
		{
			counter++;
		}
	}
	if (counter != 2)
	{
		throw invalid_argument("It's not a rectangle.");
	}
	counter = 1;
	int index = 0;
	for (int i = 1; i <= 3; i++)
	{
		if (coordinates[i][0] != first)
		{
			first = coordinates[i][0];
			tX2 = coordinates[i][0];
			index = i;
			break;
		}
	}
	for (int i = 1; i <= 3; i++)
	{
		if (coordinates[i][0] == first)
		{
			if (index == i)
			{
				continue;
			}
			counter++;
		}
	}
	if (counter != 2)
	{
		throw invalid_argument("It's not a rectangle.");
	}

	counter = 1;
	first = coordinates[0][1];
	tY1 = coordinates[0][1];
	for (int i = 1; i <= 3; i++)
	{
		if (coordinates[i][1] == first)
		{
			counter++;
		}
	}
	if (counter != 2)
	{
		throw invalid_argument("It's not a rectangle.");
	}
	counter = 1;
	for (int i = 1; i <= 3; i++)
	{
		if (coordinates[i][1] != first)
		{
			first = coordinates[i][1];
			index = i;
			tY2 = coordinates[i][1];
			break;
		}
	}
	for (int i = 1; i <= 3; i++)
	{
		if (coordinates[i][1] == first)
		{
			if (index == i)
			{
				continue;
			}
			counter++;
		}
	}
	if (counter != 2)
	{
		throw invalid_argument("It's not a rectangle.");
	}
    swap(tX1, tX2);
    swap(tY1, tY2);
    x1 = tX1;
    x2 = tX2;
    y1 = tY1;
    y2 = tY2;

}

double Rectangle::length()
{
	return (abs(x1 - x2) > abs(y1 - y2)) ? abs(x1 - x2) : abs(y1 - y2);
}

double Rectangle::width()
{
	return (abs(x1 - x2) < abs(y1 - y2)) ? abs(x1 - x2) : abs(y1 - y2);
}

double Rectangle::perimeter()
{
	return (abs(x1 - x2) + abs(y1 - y2)) * 2;
}


double Rectangle::area()
{
	return abs(x1 - x2) * abs(y1 - y2);
}

bool Rectangle::square()
{
	return (abs(x1 - x2) - abs(y1 - y2)) <= 1e-6;
}

void Rectangle::draw()
{
    int integerX1 = floor(x1);
    int integerX2 = floor(x2);
    int integerY1 = floor(y1);
    int integerY2 = floor(y2);
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            if (i > integerX1 && i < integerX2 && j > integerY1 && j < integerY2)
            {
                cout << setw(2) << " ";
            }
            else if ( (i == integerX1 && j >= integerY1 && j <= integerY2) || (i == integerX2 && j >= integerY1 && j <= integerY2) || ( j == integerY1 && i >= integerX1 && i <= integerX2 ) || ( j == integerY2 && i >= integerX1 && i <= integerX2))
            {
                cout << setw(2) << perimeterCharacter;
            } else
            {
                cout << setw(2) << fillCharacter;
            }
        }
        cout << endl;
    }
}

void Rectangle::setFillCharacter(char c)
{
    fillCharacter = c;
}

void Rectangle::setPerimeterCharacter(char c)
{
    perimeterCharacter = c;
}