#pragma once
#include "Shape.h"
class ThreeDimensionalShape :
	public Shape
{
public:
	ThreeDimensionalShape();
	virtual double getArea() const;
	virtual double getVolume() const;
};

