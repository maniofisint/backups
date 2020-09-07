#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

class Point
{
public:
    Point(double = 0, double = 0);

    void setX(double);
    double getX() const;
    void setY(double);
    double getY() const;

    double distance(const Point &p) const;

    void print() const;
private:
    double x;
    double y;
};

#endif // POINT_H_INCLUDED
