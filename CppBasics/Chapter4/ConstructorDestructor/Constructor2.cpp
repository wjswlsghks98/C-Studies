#include <iostream>
using namespace std;

class SimpleClass
{
    private: 
        int num1, num2;
    public:
        SimpleClass(int n1=0, int n2=0)
        {
            num1 = n1; num2 = n2;
        }
        void ShowData() const
        {
            cout << num1 << " " << num2 << endl;
        }
};

int main(void)
{
    SimpleClass sc1(); // declaration of original function
    SimpleClass mysc = sc1();
    mysc.ShowData();
    return 0;
}

SimpleClass sc1() // function return is in the form of SimpleClass class
{
    SimpleClass sc(20, 30);
    return sc;
}