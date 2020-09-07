#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED
#include "Polygon.h"

//Axis-aligned rectangle
class Rectangle : public Polygon
{
public:
    Rectangle();
    Rectangle(Point, Point);
    double diameter() const;
    virtual double area() const;
    virtual void print() const;
};


#endif // RECTANGLE_H_INCLUDED
