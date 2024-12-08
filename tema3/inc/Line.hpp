#ifndef LINE_HPP
#define LINE_HPP

#include "Point.hpp"

class Line
{
private:
    Point p1;
    Point p2;

public:
    Line(const Point& p1, const Point& p2);
    const Point& getP1() const;
    const Point& getP2() const;
    double getDistanceSquared() const;
    Line& operator=(const Line& right);
};

#endif