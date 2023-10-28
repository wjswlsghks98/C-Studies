#include <iostream>
using namespace std;

class SoSimple
{
    private:
        int num1;
        mutable int num2; // const함수 내부에서는 변경을 예외적으로 허용한다. 
    public:
        SoSimple(int n1, int n2) : num1(n1), num2(n2)
        { }
        void ShowSimpleData() const
        {
            cout << num1 << ", " << num2 << endl;
        }
        void CopyToNum2() const // const 함수!
        {
            num2 = num1; // num2는 멤버 변수가 아니기 때문에 const를 붙여도 무방하다. 
        }
};

int main(void)
{
    SoSimple sm(1, 2);
    sm.ShowSimpleData();
    sm.CopyToNum2();
    sm.ShowSimpleData();
    return 0;
}