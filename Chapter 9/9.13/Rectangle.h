#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
	// Rectangle(double = 0.0, double = 0.0, double = 1.0, double = 1.0, double = 1.0, double =0.0, double = 0.0, double = 1.0);
	Rectangle(double[4][2]);
	double length();
	double width();
	double perimeter();
	double area();
	bool square();
    void draw();
    void setPerimeterCharacter(char = '#');
    void setFillCharacter(char = '*');
private:
	double x1;
	double y1;
	double x2;
	double y2;
    char perimeterCharacter;
    char fillCharacter;
};

#endif