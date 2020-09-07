#include <iostream>
#include "Point.h"
#include "Polygon.h"
#include "Triangle.h"
using namespace std;

int main()
{
    Point v1;
    Point v2(0, 3);
    Point v3(4, 0);

    Polygon p(3);
    p.setVertex(0, v1);
    p.setVertex(1, v2);
    p.setVertex(2, v3);

    p.print();
    cout << "Perimeter of polygon is: " << p.perimeter() << endl;

    cout << endl << "----------------------------------" << endl;

    Triangle t1;
    t1.setVertex(0, v1);
    t1.setVertex(1, v2);
    t1.setVertex(2, v3);
    t1.print();
    cout << "Perimeter of triangle is: " << t1.perimeter() << endl;
    cout << "Area of triangle is: " << t1.area() << endl;

    cout << endl << "----------------------------------" << endl;

    Point v[3];
    v[1].setX(6);
    v[1].setY(0);
    v[2].setX(0);
    v[2].setY(8);
    Triangle t2(v);
    t2.print();
    cout << "Perimeter of triangle is: " << t2.perimeter() << endl;
    cout << "Area of triangle is: " << t2.area() << endl;

    return 0;
}
