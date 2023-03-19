#include <iostream>
using namespace std;

int main(void)
{
    const int num = 12;
    const int* ptr = &num;
    const int* (&refptr) = ptr;

    cout << num << endl;
    cout << *ptr << endl;
    cout << *refptr << endl;
    return 0;
}