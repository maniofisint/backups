#ifndef Polygon_H_INCLUDED
#define Polygon_H_INCLUDED

#include "Point.h"

class Polygon
{
public:
    Polygon(int);

    void setSize(int);
    int getSize() const;

    void setVertex(int, Point);
    Point getVertex(int) const;

    //virtual double area() const;// = 0; //Pure virtual function
    double perimeter() const;
    virtual void print() const;
//private:
protected:
    Point *vertices;
    int size;
};

#endif // Polygon_H_INCLUDED


