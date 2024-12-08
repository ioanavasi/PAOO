#include "Point.hpp"

Point::Point(double x, double y) : x(x), y(y)
{
}

Point::Point(const Point& p) : x(p.x), y(p.y)
{
}

double Point::getX() const 
{
    return this->x;
}

double Point::getY() const
{
    return this->y;
}

Point& Point::operator=(const Point& right)
{
    this->x = right.x;
    this->y = right.y;
    return *this;
}