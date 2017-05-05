#pragma once
#include "ThreeDimensionalShape.h"
class Cube : public ThreeDimensionalShape
{
public:
	Cube(double);
	virtual double getArea() const;
	virtual double getVolume() const;
private:
	double side;
};

