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
        void ShowRecInfo(void)
        {
            cout << "좌 상단: " << '[' << upLeft.x << ", ";
            cout << upLeft.y << ']' << endl;

            cout << "우 하단: " << '[' << lowRight.x << ", ";
            cout << lowRight.y << ']' << endl << endl;
        }
};

int main(void)
{
    Point pos1 = {-2, 4};
    Point pos2 = {5, 9};
    Rectangle rec = {pos2, pos1};
    // Fault인 이유는, 잘못된 포인트 정보가 입력되어도, 그것이 반영되기 어렵기 때문이다. 
    // 따라서 멤버변수를 public으로 두는 것이 아니라, private하게 두어서 class 안에서만 접근 가능하도록 하고,
    // 잘못된 값이 저장되지 않도록 별도의 로직 필요.
    rec.ShowRecInfo();
    return 0;
}