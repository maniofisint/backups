#include "Point.h"
#include <iostream>
#include <cmath>
using namespace std;

Point::Point(double xx, double yy)
{
    setX(xx);
    setY(yy);
}

void Point::setX(double xx)
{
    x = xx;
}

double Point::getX() const
{
    return x;
}

void Point::setY(double yy)
{
    y = yy;
}

double Point::getY() const
{
    return y;
}

double Point::distance(const Point &p) const
{
    return sqrt((x - p.getX()) * (x - p.getX())
              + (y - p.getY()) * (y - p.getY()));
}

void Point::print() const
{
    cout << "(" << x << ", " << y << ")" << endl;
}
