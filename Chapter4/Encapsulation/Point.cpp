#include <iostream>
#include "Point.h"

Point::Point(const int &x, const int &y)
    : xpos(x), ypos(y)
{
    //
}

void Point::ShowPointInfo() const
{
    std::cout << "[" << xpos << ", " << ypos << "]" << std::endl;
}