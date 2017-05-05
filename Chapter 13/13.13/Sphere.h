#pragma once
#include "ThreeDimensionalShape.h"
class Sphere :
	public ThreeDimensionalShape
{
public:
	Sphere(double);
	virtual double getArea() const;
	virtual double getVolume() const;
private:
	double radius;
	const double pi = 3.14;
};

