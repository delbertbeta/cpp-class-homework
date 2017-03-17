#include <stdexcept>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(double l, double w)
{
    if (l > 0 && l < 20)
    {
        length = l;
    }
    else 
    {
        throw invalid_argument("Length must between 0 and 20");
    }

    if (w > 0 && w < 20)
    {
        width = w;
    }
    else 
    {
        throw invalid_argument("Width must between 0 and 20");
    }
    
}

double Rectangle::getLength()
{
    return length;
}

double Rectangle::getWidth()
{
    return width;
}

void Rectangle::setWidth(double w)
{
    if (w > 0 && w < 20)
    {
        width = w;
    }
    else 
    {
        throw invalid_argument("Width must between 0 and 20");
    }
}

void Rectangle::setLength(double l)
{
    if (l > 0 && l < 20)
    {
        length = l;
    }
    else 
    {
        throw invalid_argument("Length must between 0 and 20");
    }
}

double Rectangle::area()
{
    return width * length;
}

double Rectangle::perimeter()
{
    return 2 * (width + length);
}