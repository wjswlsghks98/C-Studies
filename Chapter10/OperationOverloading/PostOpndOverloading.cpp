#include <iostream>
using namespace std;

class Point
{
    private: 
        int xpos, ypos;
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y) {}
        void ShowPosition() const
        {
            cout << '[' <<xpos << ", " << ypos << ']' << endl;
        }
        Point& operator++() // 전위 증가
        {
            xpos += 1; ypos += 1;
            return *this;
        }
        const Point operator++(int) // 후위 증가
        {
            const Point retobj(xpos, ypos); // 복사본은 증가하면 안되기 때문에 const로 선언
            xpos += 1; ypos += 1;
            return retobj;
        }
        friend Point& operator--(Point &ref);
        friend const Point operator--(Point &ref, int);
};

Point& operator--(Point &ref) // 전위 감소
{
    ref.xpos -= 1; ref.ypos -= 1; return ref;
}
const Point operator--(Point &ref, int) // 후위 감소
{
    const Point retobj(ref);
    ref.xpos -= 1;
    ref.ypos -= 1;
    return retobj;
}

int main(void)
{
    Point pos(3, 5);
    Point cpy;
    cpy = pos--;
    cpy.ShowPosition();
    pos.ShowPosition();

    cpy = pos++;
    cpy.ShowPosition();
    pos.ShowPosition();
    return 0;
}