#include "Line.hpp"
#include <iostream>

int main()
{
    Point p1(2.5, 4.32);
    Point p2(-2.01, 7.2);
    Line l(p1, p2);
    std::cout<<l.getDistanceSquared()<<std::endl;


    Line *lptr = new Line(p1, p2);
    std::cout<<lptr->getDistanceSquared()<<std::endl;
    delete lptr;
}