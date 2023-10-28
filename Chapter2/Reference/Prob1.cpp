#include <iostream>
using namespace std;

void increment(int &num);

void reverse(int &num);

int main(void)
{
    int val;
    cout << "Input any integer: ";
    cin >> val;

    cout << "Before any process: " << val << endl;
    increment(val);
    cout << "After increment: " << val << endl;
    reverse(val);
    cout << "After sign reverse: " << val << endl;

    return 0;
}

void increment(int &num)
{
    num++;
}

void reverse(int &num)
{
    num *= (-1);
}
