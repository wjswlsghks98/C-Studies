#include <iostream>
using namespace std;

class SoSimple
{
    public:
        virtual void ShowSimpleInfo()
        {
            cout << "SoSimple Base Class" << endl;
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
    SoSimple simObj;
    SoSimple& ref = simObj;

    try
    {
        SoComplex& comRef = dynamic_cast<SoComplex&>(ref); // 참조형을 대상으로 dynamic_cast를 진행할 경우에는 bad_cast 예외가 발생할 수 있음.
        comRef.ShowSimpleInfo();
    }
    catch(bad_cast expt)
    {
        cout << expt.what() << endl;
    }
    return 0;
}