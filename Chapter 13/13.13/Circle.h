#pragma once
#include "TwoDimensionalShape.h"
class Circle :
	public TwoDimensionalShape
{
public:
	Circle(double);
	virtual double getArea() const;
private:
	double radius;
	const double pi = 3.14;
};

