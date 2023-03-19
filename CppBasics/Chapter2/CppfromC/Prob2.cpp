#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(void)
{
    srand(time(NULL));
    for(int i=0;i<5;i++)
    {
        int a = rand() % 100;
        cout << a << endl;
    }
    
}