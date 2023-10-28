#include <iostream>
#include "Point.h"
#include "Rectangle.h"
using namespace std;

int main(void)
{
    Point pos1;
    if(!pos1.Init(-2,4))
        cout << "초기화 실패" << endl;
    if(!pos1.Init(2,4))
        cout << "초기화 실패" << endl;

    Point pos2;
    if(!pos2.Init(5,9))
        cout << "초기화 실패" << endl;

    Rectangle rec;
    if(!rec.Init(pos2, pos1))
        cout << "직사각형 초기화 실패" << endl;

    if(!rec.Init(pos1, pos2))
        cout << "직사각형 초기화 실패" << endl;

    rec.ShowRecInfo();
    return 0;
}