#ifndef __RING_H__
#define __RING_H__
#include "Circle.h"

class Ring
{
    private:
        Circle inner, outer;
    public:
        Ring(const int &x1, const int &y1, const int &r1, 
             const int &x2, const int &y2, const int &r2);
        void ShowRingInfo() const;
};

#endif