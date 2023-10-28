#include <iostream>
using namespace std;

class SoSimple
{
    private:
        int num;
    public:
        SoSimple(int n) : num(n)
        { }
        SoSimple(const SoSimple &copy) : num(copy.num)
        {
            cout << "Called SoSimple(const SoSimple &copy)" << endl;
        }
        void ShowData()
        {
            cout << "num: " << num << endl;
        }
};

void SimpleFuncObj(SoSimple ob)
{
    ob.ShowData();
}

int main(void)
{
    SoSimple obj(7);
    cout << "함수 호출 전" << endl;
    SimpleFuncObj(obj); // ob 라는 객체 메모리 할당과 동시에 obj로 초기화! --> 복사 생성자를 통해서 접근
    cout << "함수 호출 후" << endl;
    return 0;
}