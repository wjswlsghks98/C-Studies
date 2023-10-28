#ifndef __POINT_H__
#define __POINT_H__

class Point
{
    private:
        int x;
        int y;

    public:
        bool Init(int xpos, int ypos);
        int GetX() const;
        int GetY() const;
        bool SetX(const int &xpos);
        bool SetY(const int &ypos);
};

#endif