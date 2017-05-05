#include "Cube.h"



Cube::Cube(double s)
{
	side = s;
}

double Cube::getArea() const
{
	return 6 * side * side;
}

double Cube::getVolume() const
{
	return side * side * side;
}
