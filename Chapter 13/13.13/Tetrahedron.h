#pragma once
#include "ThreeDimensionalShape.h"
class Tetrahedron :
	public ThreeDimensionalShape
{
public:
	Tetrahedron(double);
	virtual double getArea() const;
	virtual double getVolume() const;
private:
	double side;
};

