#include <iostream>
using namespace std;

int flip(int num)
{
    int ones = num%10;
    int tens = ((num - num%10)%100)/10;
    int hnds = num/100;
    return ones * 100 + tens * 10 + hnds;
}

int main(void)
{
    int num1, num2;
    cin >> num1 >> num2;
    if (flip(num1) > flip(num2))
        cout << flip(num1);
    else
        cout << flip(num2);
    return 0;
}