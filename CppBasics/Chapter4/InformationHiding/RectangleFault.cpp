#include <iostream>
using namespace std;

class Point
{
    public: 
        int x;
        int y;
};

class Rectangle
{
    public:
        Point upLeft;
        Point lowRight;
    public:
        void ShowRecInfo()
        {
            cout << "Left Top: " << "[" << upLeft.x << ", ";
            cout << upLeft.y << "]" << endl;

            cout << "Right Bottom: " << "[" << lowRight.x << ", ";
            cout << lowRight.y << "]" << endl;
        }
};

int main(void)
{
    // If member variables are set as declared as public, 
    // they can be assigned same as struct
    Point pos1 = {-2, 4};
    Point pos2 = {5, 9};
    Rectangle rec = {pos2, pos1};
    rec.ShowRecInfo();
    return 0;
}