#include <iostream>
#include <new>
using namespace std;

int main(void)
{
    int num = 0;
    try
    {
        while(1)
        {
            num++;
            cout << num << "번째 할당 시도" << endl;
            new int[10000000][10000000]; // 생각보다 너무 잘 돌아감. 주의
        }
    }
    catch(bad_alloc &bad)
    {
        cout << bad.what() << endl;
        cout << "더 이상 할당 불가!" << endl;
    }
    return 0;
}