#include "Line.hpp"

Line::Line(const Point& p1, const Point& p2) : p1(p1), p2(p2)
{
}
const Point& Line::getP1() const
{
    return p1;
}
const Point& Line::getP2() const
{
    return p2;
}
double Line::getDistanceSquared() const
{
    return (p1.getX() - p2.getX())*(p1.getX() - p2.getX()) + (p1.getY() - p2.getY())*(p1.getY() - p2.getY());
}
