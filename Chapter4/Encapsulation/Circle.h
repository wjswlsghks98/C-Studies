#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "Point.h"

class Circle
{
    private:
        Point center;
        int radius;
    public:
        Circle(const int &x, const int &y, const int &r);
        void ShowCircleInfo() const;
};

#endif