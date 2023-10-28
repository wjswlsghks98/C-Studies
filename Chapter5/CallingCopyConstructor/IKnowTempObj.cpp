#include <iostream>
using namespace std;

class Temporary
{
  private:
    int num;
  public:  
    Temporary(int n) : num(n)
    {
        cout << "Create obj: " << num << endl;
    }
    ~Temporary()
    {
        cout << "Destroy obj: " << num << endl;
    }
    void ShowTempInfo()
    {
        cout << "My num is " << num << endl;
    }
};

int main(void)
{
    Temporary(100); // 이렇게 선언하면 참조값이 반환됨!
    cout << "********* after make!" << endl << endl;

    Temporary(200).ShowTempInfo();
    cout << "********* after make!" << endl << endl;

    const Temporary &ref = Temporary(300); // 참조값이 반환되기 때문에 이와 같은 문장의 구성도 가능
    // 임시 변수가 아니라 실제 참조자와 연결이 되었기 때문에 바로 소멸자가 호출되지 않고 메인함수가 끝날 때까지 유지됨.
    cout << "********* after make!" << endl << endl;
    return 0;
}