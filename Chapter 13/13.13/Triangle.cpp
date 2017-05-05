#include "Triangle.h"

Triangle::Triangle(double b, double h)
{
	bottom = b;
	height = h;
}

double Triangle::getArea() const
{
	return bottom * height / 2;
}
