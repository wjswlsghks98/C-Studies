#include <iostream>
using namespace std;

class Point 
{
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y) { }
        void ShowPosition() const
        {
            cout << '[' <<xpos << ", " << ypos << ']' << endl;
        }
        Point& operator+=(const Point &ref)
        {
            xpos += ref.xpos; ypos += ref.ypos;
            return *this;
        }
        Point& operator-=(const Point &ref)
        {
            xpos -= ref.xpos; ypos -= ref.ypos;
            return *this;
        }
        friend bool operator==(const Point &pos1, const Point &pos2);
        friend bool operator!=(const Point &pos1, const Point &pos2);
};

// Problem 3 attached together.
bool operator==(const Point &pos1, const Point &pos2)
{
    if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos) return true;
    else return false;
}

bool operator!=(const Point &pos1, const Point &pos2)
{
    if (pos1 == pos2) return false;
    else return true;
}

int main(void)
{
    Point pos1(3, 4);
    Point pos2(10, 20);
    Point pos3(5, 5);
    Point pos4(8, 19);
    (pos1 += pos2).ShowPosition();
    cout << (pos1 != pos4) << endl;
    (pos1 -= pos3).ShowPosition();
    
    cout << (pos1 == pos4) << endl;
    return 0;
}