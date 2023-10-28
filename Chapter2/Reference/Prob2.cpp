#include <iostream>
using namespace std;

void SwapPointer(int *(&ptr1), int *(&ptr2));

int main(void)
{
    int num1 = 5, num2 = 10;
    int *ptr1 = &num1, *ptr2 = &num2;
    SwapPointer(ptr1, ptr2);
    cout << "Value of ptr1: " << *ptr1 << endl;
    cout << "Value of ptr2: " << *ptr2 << endl;
    return 0;
}

void SwapPointer(int *(&ptr1), int *(&ptr2))
{
    int *tmp = ptr1;
    ptr1 = ptr2;
    ptr2 = tmp;
}