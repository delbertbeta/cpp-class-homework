#include "Sphere.h"



Sphere::Sphere(double r)
{
	radius = r;
}

double Sphere::getArea() const
{
	return 4 * pi * radius * radius;
}

double Sphere::getVolume() const
{
	return 4 / 3 * pi * radius * radius * radius;
}
