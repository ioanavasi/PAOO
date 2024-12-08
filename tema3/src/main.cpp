#include "Line.hpp"
#include <iostream>

int main()
{
    Point p1(2.5, 4.32);
    Point p2(-2.01, 7.2);

    Line l1(p1, p2);
    std::cout<<l1.getDistanceSquared()<<std::endl;

    Line l2 = l1;
    std::cout<<l2.getDistanceSquared()<<std::endl;
    
    return 0;
}