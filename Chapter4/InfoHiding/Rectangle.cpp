#include <iostream>
#include "Rectangle.h"

bool Rectangle::Init(const Point &ul, const Point &lr)
{
    // GetX 와 GetY 모두 const로 정의된 함수라서 compile error 없는 것임.
    // GetX나 GetY가 const 함수가 아니라면, ul과 lr은 변화할 수 있는 가능성이 있기 때문에 compiler 자체에서 이를 차단.
    // 따라서 const로 파라미터를 정의한 함수 내부에서 또 다른 함수를 호출할 때, 
    // 해당 함수에 const를 추가해야 함.
    if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY()) 
    {
        std::cout << "잘못된 위치정보 전달" << std::endl;
        return false;
    }
    upLeft = ul;
    lowRight = lr;
    return true;
}

void Rectangle::ShowRecInfo() const
{
    std::cout << "좌 상단: " << '[' << upLeft.GetX() << ", ";
    std::cout << upLeft.GetY() << ']' << std::endl;

    std::cout << "우 하단: " << '[' << lowRight.GetX() << ", ";
    std::cout << lowRight.GetY() << ']' << std::endl << std::endl;
}