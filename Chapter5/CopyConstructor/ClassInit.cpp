#include <iostream>
using namespace std;

class SoSimple
{
    private:
        int num1, num2;
    public:
        SoSimple(const int &n1, const int &n2)
            : num1(n1), num2(n2)
        {
            //
        }

        explicit SoSimple(const SoSimple &copy) 
        // explicit을 추가하면 아래의 SoSimple sim2 = sim1에서 SoSimple sim2(sim1)으로의 
        // 묵시적 변환은 일어나지 않는다. 따라서 Default 복사생성자를 막고 싶으면 이렇게 정의.
            : num1(copy.num1), num2(copy.num2)
        {
            cout << "Called SoSimple(SoSimple &copy)" << endl;
        }
        void ShowSimpleData()
        {
            cout << num1 << endl;
            cout << num2 << endl;
        }
};

int main(void)
{
    SoSimple sim1(15,30);
    cout << "생성 및 초기화 직전" << endl;
    // SoSimple sim2 = sim1; 
    SoSimple sim2(sim1); //으로 변환되어서 진행됨.
    cout << "생성 및 초기화 직후" << endl;
    sim2.ShowSimpleData();
    return 0;
}