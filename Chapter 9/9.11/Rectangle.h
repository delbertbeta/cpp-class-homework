#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
    public:
        Rectangle(double = 1.0, double = 1.0);
        double getLength();
        double getWidth();
        double perimeter();
        double area();
        void setLength(double);
        void setWidth(double);
    private:
        double length;
        double width;
};

#endif