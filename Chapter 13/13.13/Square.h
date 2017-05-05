#pragma once
#include "TwoDimensionalShape.h"
class Square :
	public TwoDimensionalShape
{
public:
	Square(double);
	virtual double getArea() const;
private:
	double side;
};

