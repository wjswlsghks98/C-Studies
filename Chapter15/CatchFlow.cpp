#include <iostream>
using namespace std;

class AAA
{
    public:
        void ShowYou() { cout << "AAA exception!" << endl; }
};

class BBB : public AAA
{
    public:
        void ShowYou() { cout << "BBB exception!" << endl; }
};

class CCC : public BBB
{
    public:
        void ShowYou() { cout << "CCC exception!" << endl; }
};

void ExceptionGenerator(int expn)
{
    if (expn == 1)
        throw AAA();
    else if (expn == 2)
        throw BBB();
    else
        throw CCC();
}

int main(void)
{
    try
    {
        ExceptionGenerator(3);
        ExceptionGenerator(2);
        ExceptionGenerator(1);
    }
    catch(CCC& expn) // catch의 작동 특성상 가장 깊은 상속자가 가장 먼저 검색되어야 함. 검출 안됨.
    {
        cout << "catch(CCC& expn)" << endl;
        expn.ShowYou();
    }
    catch(BBB& expn)
    {
        cout << "catch(BBB& expn)" << endl;
        expn.ShowYou();
    }
    catch(AAA& expn)
    {
        cout << "catch(AAA& expn)" << endl;
        expn.ShowYou();
    }
    
    return 0;
}