#include <iostream>
using namespace std;

class SoSimple
{
    public:
        virtual void ShowSimpleInfo()
        {
            cout << "So Simple Base Class" << endl;
        }
};

class SoComplex : public SoSimple
{
    public:
        void ShowSimpleInfo()
        {
            cout << "SoComplex Derived Class" << endl;
        }
};

int main(void)
{
    SoSimple * simPtr = new SoComplex;
    SoComplex * comPtr = dynamic_cast<SoComplex*>(simPtr); // class가 polymorphic인 경우 dynamic cast 를 다음과 같이 사용 가능.
    // 기본 class 에서 유도 클래스로의 형 변환은 원래 dynamic_cast에서 허용하지 않지만, polymorphic한 경우에 한정해서 허용.
    comPtr->ShowSimpleInfo();
}