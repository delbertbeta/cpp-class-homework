#include "Circle.h"\

#include <stdexcept>

using std::invalid_argument;

Circle::Circle(double r)
{
	if (r >= 0)
	{
		radius = r;
	}
	else
	{
		throw invalid_argument("Radius must be >= 0.0");
	}
}

double Circle::getArea() const
{
	return pi * radius * radius;
}

