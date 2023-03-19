#include <iostream>
using namespace std;

void Increment(int &ref);
void ChangeSign(int &ref);

int main(void)
{
    int num = 10;
    Increment(num);
    cout << num << endl;
    ChangeSign(num);
    cout << num << endl;
    return 0;
}

void Increment(int &ref)
{
    ref++;
}

void ChangeSign(int &ref)
{
    ref *= (-1);
}