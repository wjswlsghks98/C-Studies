#ifndef __POINT_H__
#define __POINT_H__

class Point
{
    private:
        int xpos, ypos;
    public:
        Point(const int &x, const int &y);
        void ShowPointInfo() const;
};

#endif