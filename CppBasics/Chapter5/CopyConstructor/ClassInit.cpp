#include <iostream>
using namespace std;

class SoSimple
{
    private:
        int num1, num2;
    public:
        SoSimple(int n1, int n2) : num1(n1), num2(n2) {}
        explicit SoSimple(const SoSimple &copy) : num1(copy.num1), num2(copy.num2) 
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
    SoSimple sim1(15, 30);
    cout << "Before" << endl;
    // SoSimple sim2 = sim1; --> using explicit prevents implicit transforms
    SoSimple sim2(sim1); // --> only this type of initialization possible
    cout << "After" << endl;
    sim2.ShowSimpleData();
    return 0;
}