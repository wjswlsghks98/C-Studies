#ifndef __PROB1_H__
#define __PROB1_H__

#include <iostream>
using namespace std;

class Point
{
    private:
        int xpos, ypos;
    public:
        Point(int x, int y)
            : xpos(x), ypos(y)
        {
            //
        }
        void ShowPointInfo() const
        {
            cout << "[" << xpos << ", " << ypos << "]" << endl;
        }
};

class Circle
{
    private:
        Point Xc;
        int radius;
    public:
        Circle(int px, int py, int r)
            : Xc(px, py), radius(r)
        {
            //
        }
        
        void ShowCircleInfo() const
        {   
            cout << "radius: " << radius << endl;
            Xc.ShowPointInfo();        
        }
};

class Ring
{
    private:
        Circle InnerCircle, OuterCircle;
    public:
        Ring(int inx, int iny, int inr, int outx, int outy, int outr)
            : InnerCircle(inx,iny,inr), OuterCircle(outx,outy,outr)
        {
            //
        }

        void ShowRingInfo() const
        {
            cout << "Inner Circle Info..." << endl;
            InnerCircle.ShowCircleInfo();
            cout << "Outer Circle Info..." << endl;
            OuterCircle.ShowCircleInfo();
        }

};

#endif