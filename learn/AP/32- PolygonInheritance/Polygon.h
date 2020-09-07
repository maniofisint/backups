#ifndef POLYGON_H_INCLUDED
#define POLYGON_H_INCLUDED

#include "Point.h"

class Polygon
{
public:
    Polygon(int);

    void setSize(int);
    int getSize() const;

    void setVertex(int, Point);
    Point getVertex(int) const;

    double perimeter() const;
    void print() const;
//private:
protected:
    Point *vertices;
    int size;
};

#endif // POLYGON_H_INCLUDED


