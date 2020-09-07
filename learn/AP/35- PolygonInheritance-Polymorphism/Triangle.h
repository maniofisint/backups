#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED
#include "Polygon.h"

class Triangle : public Polygon
{
public:
    Triangle();
    Triangle(Point *v);
    virtual double area() const;
    virtual void print() const;
};

#endif // TRIANGLE_H_INCLUDED
