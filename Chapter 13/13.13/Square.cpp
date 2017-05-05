#include "Square.h"



Square::Square(double s)
{
	side = s;
}

double Square::getArea() const
{
	return side * side;
}

