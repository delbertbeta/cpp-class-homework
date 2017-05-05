#include "Tetrahedron.h"
#include <cmath>


Tetrahedron::Tetrahedron(double s)
{
	side = s;
}

double Tetrahedron::getArea() const
{
	return side * side * sqrt(3);
}

double Tetrahedron::getVolume() const
{
	return side * side * side * sqrt(2) / 24;
}

