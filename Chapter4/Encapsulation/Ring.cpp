#include <iostream>
#include "Ring.h"

Ring::Ring(const int &x1, const int &y1, const int &r1, 
           const int &x2, const int &y2, const int &r2)
    : inner(x1,y1,r1), outer(x2,y2,r2)
{
    //
}

void Ring::ShowRingInfo() const 
{
    std::cout << "Inner Circle Info..." << std::endl;
    inner.ShowCircleInfo();
    std::cout << "Outer Circle Info..." << std::endl;
    outer.ShowCircleInfo();
}