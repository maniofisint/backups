#include "Triangle.h"
#include <cmath>
#include <iostream>
using namespace std;

Triangle::Triangle()
    :Polygon(3)
{}

Triangle::Triangle(Point *v)
    :Polygon(3)
{
    setVertex(0, v[0]);
    setVertex(1, v[1]);
    setVertex(2, v[2]);
}

double Triangle::area() const
{
    //double a = getVertex(0).distance(getVertex(1));
    //double b = getVertex(1).distance(getVertex(2));
    //double c = getVertex(2).distance(getVertex(0));

    double a = vertices[0].distance(vertices[1]);
    double b = vertices[1].distance(vertices[2]);
    double c = vertices[2].distance(vertices[0]);

    double s = (a + b + c) / 2;

    return sqrt(s * (s - a) * (s - b) * (s - c));
}
void Triangle::print() const
{
    cout << "It's Triangle." << endl;
    Polygon::print();
    //cout << "Area is: " << area() << endl;
}
