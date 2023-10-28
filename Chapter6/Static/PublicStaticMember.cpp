#include <iostream>
using namespace std;

class SoSimple
{
    public:
        static int simObjCnt;
    public:
        SoSimple()
        {
            simObjCnt++;
        }  
};

int SoSimple::simObjCnt = 0;

int main(void)
{
    cout << SoSimple::simObjCnt <<"번째 SoSimple 객체" << endl;
    SoSimple sim1;
    SoSimple sim2;

    cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl; // 멤버 변수가 아니기 때문에 이렇게 접근 가능. 
    cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl;
    cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl;
    return 0;
}