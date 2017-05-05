#include "Shape.h"
#include "TwoDimensionalShape.h"
#include "ThreeDimensionalShape.h"
#include "Circle.h"
#include "Cube.h"
#include "Sphere.h"
#include "Square.h"
#include "Tetrahedron.h"
#include "Triangle.h"

#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

void shapeHandle(Shape * shape);

int main()
{
	vector<Shape*> shapes;
	
	shapes.push_back(new Circle(5.0));
	shapes.push_back(new Square(5.0));
	shapes.push_back(new Triangle(5.0, 2.0));
	
	shapes.push_back(new Sphere(5.0));
	shapes.push_back(new Cube(5.0));
	shapes.push_back(new Tetrahedron(5.0));

	for (size_t i = 0; i < shapes.size(); i++)
	{
		shapeHandle(shapes[i]);
	}

	system("pause");
}

void shapeHandle(Shape* shape)
{
	cout << typeid(*shape).name() << " - ";
	TwoDimensionalShape *twoDimensionalShape = dynamic_cast<TwoDimensionalShape*>(shape);
	if (twoDimensionalShape != NULL)
	{
		cout << "Area: " << shape->getArea() << endl;
	}
	else
	{
		cout << "Area: " << shape->getArea() << " - Volume: " << shape->getVolume() << endl;
	}
	
}