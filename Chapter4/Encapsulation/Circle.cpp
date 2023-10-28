#include <iostream>
#include "Circle.h"

Circle::Circle(const int &x, const int &y, const int &r)
    : center(x, y), radius(r)
{
    //
}

void Circle::ShowCircleInfo() const
{
    std::cout << "radius: " << radius << std::endl;
    center.ShowPointInfo();
}