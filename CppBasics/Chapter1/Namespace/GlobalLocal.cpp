#include <iostream>
using namespace std;

int val = 100;
int SimpleFunc(void)
{
    int val = 20;
    val += 3;
    ::val += 7;
    return val;
}

int main(void)
{
    int ans = SimpleFunc();
    cout << "Local Variable : " << ans << endl;
    cout << "Global Variable : " << val << endl;
}