#include <iostream>
using namespace std;

typedef struct __Point
{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2);

int main(void)
{
    Point *p1 = new Point;
    Point *p2 = new Point;
    p1->xpos = 10; p1->ypos = 20;
    p2->xpos = 20; p2->ypos = 30;
    Point &p3 = PntAdder(*p1, *p2);
    cout << p3.xpos << " " << p3.ypos << endl;
    delete p1;
    delete p2;
    delete &p3;
    return 0;
}

Point& PntAdder(const Point &p1, const Point &p2)
{
    Point *p3 = new Point; 
    p3->xpos = p1.xpos + p2.xpos;
    p3->ypos = p1.ypos + p2.ypos;
    return *p3;
}