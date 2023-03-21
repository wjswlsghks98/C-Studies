#include <iostream>
#include "Rectangle.h"
using namespace std;

Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2)
            : upLeft(x1, y1), lowRight(x2, y2) //Member initializer
{
    // empty
}

void Rectangle::ShowRecInfo() const // This prevents from member variable from changing
{
    cout << "Left Top: " << "[" << upLeft.GetX() << ", ";
    cout << upLeft.GetY() << "]" << endl;

    cout << "Right Bottom: " << "[" << lowRight.GetX() << ", ";
    cout << lowRight.GetY() << "]" << endl << endl;
}