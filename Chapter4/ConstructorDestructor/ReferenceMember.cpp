#include <iostream>
using namespace std;

class AAA
{
    public:
        AAA()
        {
            cout << "empty object" << endl;
        }
        void ShowYourName()
        {
            cout << "I'm class AAA" << endl;
        }
};

class BBB
{
    private:
        AAA &ref; // 이니셜라이저 덕분에 선언과 동시에 초기화 가능!
        const int &num;
    public:
        BBB(AAA &r, const int &n)
            : ref(r), num(n)
        {
            //
        }
        void ShowYourName()
        {
            ref.ShowYourName();
            cout << "and" << endl;
            cout << "I ref num " << num << endl;
        }
};

int main(void)
{
    AAA obj1;
    BBB obj2(obj1, 20);
    obj2.ShowYourName();
    return 0;
}