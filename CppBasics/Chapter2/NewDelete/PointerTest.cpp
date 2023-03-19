#include <iostream>
using namespace std;

int main(void)
{
    // int arr[30] = {0};
    // cout << arr << endl;
    // cout << *(arr+1) << endl;

    int *ptr = new int;
    int &ref = *ptr;
    ref = 20;
    cout << *ptr << endl;
}