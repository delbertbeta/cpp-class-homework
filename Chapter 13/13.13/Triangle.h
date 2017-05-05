#pragma once
#include "TwoDimensionalShape.h"
class Triangle :
	public TwoDimensionalShape
{
public:
	Triangle(double, double);
	virtual double getArea() const;
private:
	double bottom;
	double height;
};

