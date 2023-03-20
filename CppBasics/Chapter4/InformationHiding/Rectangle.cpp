#include <iostream>
#include "Rectangle.h"
using namespace std;

bool Rectangle::InitMembers(const Point &ul, const Point &lr)
{
    if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY()) // note that larger y is lower
    {
        cout << "Wrong positional information" << endl;
        return false;
    }
    upLeft = ul;
    lowRight = lr;
    return true;
}

void Rectangle::ShowRecInfo() const // This prevents from member variable from changing
{
    cout << "Left Top: " << "[" << upLeft.GetX() << ", ";
    cout << upLeft.GetY() << "]" << endl;

    cout << "Right Bottom: " << "[" << lowRight.GetX() << ", ";
    cout << lowRight.GetY() << "]" << endl << endl;
}