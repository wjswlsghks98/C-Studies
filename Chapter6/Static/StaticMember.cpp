#include <iostream>
using namespace std;

class SoSimple
{
    private:
        static int simObjCnt;
    public:
        SoSimple()
        {
            simObjCnt++;
            cout << simObjCnt << "번째 SoSimple 객체" << endl;
        }
};
int SoSimple::simObjCnt = 0; // 이 부분을 생성자에 넣으면 매번 0으로 초기화 되기 때문에 따로 바깥으로 빼줘야 한다. 

class SoComplex
{
    private:
        static int cmxObjCnt;
    public:
        SoComplex()
        {
            cmxObjCnt++;
            cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
        }
        SoComplex(SoComplex &copy)
        {
            cmxObjCnt++;
            cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
        }
};
int SoComplex::cmxObjCnt = 0;

int main(void)
{
    SoSimple sim1;
    SoSimple sim2;

    SoComplex cmx1;
    SoComplex cmx2 =  cmx1;
    SoComplex();
    return 0;
}

