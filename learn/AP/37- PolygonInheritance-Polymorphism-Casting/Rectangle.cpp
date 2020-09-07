#include "Rectangle.h"
#include <cmath>
#include <iostream>
using namespace std;

Rectangle::Rectangle()
    :Polygon(4)
{}

Rectangle::Rectangle(Point bl, Point tr)
    :Polygon(4)
{

    Point br, tl;
    br.setX(tr.getX());
    br.setY(bl.getY());
    tl.setX(bl.getX());
    tl.setY(tr.getY());
    setVertex(0, bl);
    setVertex(1, br);
    setVertex(2, tr);
    setVertex(3, tl);
}

double Rectangle::area() const
{
    double a = vertices[0].distance(vertices[1]);
    double b = vertices[1].distance(vertices[2]);

    return a * b;
}

void Rectangle::print() const
{
    cout << "It's Rectangle." << endl;
    Polygon::print();
    //cout << "Area is: " << area() << endl;
}

double Rectangle::diameter() const
{
    double a = vertices[0].distance(vertices[1]);
    double b = vertices[1].distance(vertices[2]);
    return sqrt(a * a + b * b);
}
