#include <iostream>
#include "Point.h"
#include "Polygon.h"
#include "Triangle.h"
#include "Rectangle.h"

using namespace std;

int main()
{
    Point v1;
    Point v2(0, 3);
    Point v3(4, 3);
    Point v4(4, 0);

    /*Polygon p(4);
    p.setVertex(0, v1);
    p.setVertex(1, v2);
    p.setVertex(2, v3);
    p.setVertex(3, v4);

    p.print();
    cout << "Perimeter of Polygon is: " << p.perimeter() << endl;
    */
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

    Polygon *polygonPtr;
    Triangle *trianglePtr;
    cout << endl << "----------------------------------" << endl;
    /*polygonPtr = &p;
    polygonPtr->print();
    cout << "Perimeter of Polygon is: " << polygonPtr->perimeter() << endl;
    cout << endl << "----------------------------------" << endl;
    trianglePtr = &t1;
    trianglePtr->print();
    cout << "Perimeter of Triangle is: " << trianglePtr->perimeter() << endl;
    cout << "Area of triangle is: " << trianglePtr->area() << endl;*/
    cout << endl << "----------------------------------" << endl;
    //int isTriangle;
    //cin >> isTriangle;
    //if(isTriangle)
    polygonPtr = &t2;
    //else
    //    polygonPtr = &p;
    polygonPtr->print();
    cout << "Perimeter of Triangle is: " << polygonPtr->perimeter() << endl;
    //cout << "Area of triangle is: " << polygonPtr->area() << endl;

    cout << endl << "----------------------------------" << endl;
    Point v5(2, 4);
    Point v6(6, 9);
    Rectangle r(v5, v6);
    r.print();
    cout << "Perimeter of triangle is: " << r.perimeter() << endl;
    cout << "Area of triangle is: " << r.area() << endl;
    cout << endl << "----------------------------------" << endl;
    Polygon *ptr[3];
    //ptr[0] = &p;
    ptr[1] = &t1;
    ptr[2] = &r;
    for(int i = 1; i < 3; i++)
        ptr[i]->print();

    return 0;
}
