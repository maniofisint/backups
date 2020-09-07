#include "Polygon.h"
#include <stdexcept>
#include <iostream>
using namespace std;

Polygon::Polygon(int s)
{
    setSize(s);
    vertices = new Point[size];
}
void Polygon::setSize(int s)
{
    if(s < 3)
        throw invalid_argument("Size of polygon must be greater than 2.");
    else
        size = s;
}
int Polygon::getSize() const
{
    return size;
}

void Polygon::setVertex(int idx, Point p)
{
    if(idx >= size)
        throw invalid_argument("Invalid vertex index.");
    else
        vertices[idx] = p;
}
Point Polygon::getVertex(int idx) const
{
    if(idx >= size)
        throw invalid_argument("Invalid vertex index.");
    else
        return(vertices[idx]);
}

double Polygon::perimeter() const
{
    double p = vertices[0].distance(vertices[size - 1]);
    for(int i = 0; i < size - 1; i++)
        p += vertices[i].distance(vertices[i + 1]);

    return p;
}

void Polygon::print() const
{
    cout << size << " vertex of polygon:" << endl;
    for(int i = 0; i < size; i++)
        vertices[i].print();
}
