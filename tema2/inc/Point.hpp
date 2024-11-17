#ifndef POINT_HPP
#define POINT_HPP

class Point
{
private:
    double x;
    double y;

public: 
    Point(double x, double y);
    Point(const Point& p);
    double getX() const;
    double getY() const;
};
#endif