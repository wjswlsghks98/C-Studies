#include <iostream>
using namespace std;

typedef struct __Point
{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2)
{
    Point *pptr = new Point; // allocate memory in Heap 
    pptr->xpos = p1.xpos + p2.xpos;
    pptr->ypos = p1.ypos + p2.ypos;
    return *pptr; // data 
}

int main(void)
{
    Point *p_ptr1 = new Point;
    Point *p_ptr2 = new Point;

    p_ptr1->xpos = 10;
    p_ptr1->ypos = 15;

    p_ptr2->xpos = 20;
    p_ptr2->ypos = 34;

    Point &p = PntAdder(*p_ptr1, *p_ptr2);

    cout <<"[" << p.xpos << ", " << p.ypos << "]" << endl;

    delete p_ptr1;
    delete p_ptr2;
    delete &p; // address of p

    return 0;    
}