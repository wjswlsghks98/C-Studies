#include "Point.h"
#include <iostream>
using namespace std;

Point::Point(const int &xpos, const int &ypos)
{
    if(xpos < 0 || ypos < 0)
    {
        cout << "벗어난 범위의 값 전달" << endl;
    }
    x = xpos;
    y = ypos;
}

int Point::GetX() const
{
    return x;
}

int Point::GetY() const
{
    return y;
}

bool Point::SetX(const int &xpos)
{
    if (0 > xpos || xpos > 100)
    {
        cout << "벗어난 범위의 값 전달" << endl;
        return false;
    }
    x = xpos;
    return true;
}

bool Point::SetY(const int &ypos)
{
    if (0 > ypos || ypos > 100)
    {
        cout << "벗어난 범위의 값 전달" << endl;
        return false;
    }
    y = ypos;
    return true;
}