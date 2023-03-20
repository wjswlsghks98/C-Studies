#ifndef __PROB2_H__
#define __PROB2_H__

#include <iostream>
using namespace std;

class Point
{
    private:
        int xpos, ypos;
    public:
        void Init(int x, int y)
        {
            xpos = x;
            ypos = y;
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
        void Init(int px, int py, int r)
        {
            Xc.Init(px, py);
            radius = r;
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
        void Init(int inx, int iny, int inr, int outx, int outy, int outr)
        {
            InnerCircle.Init(inx,iny,inr);
            OuterCircle.Init(outx,outy,outr);
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