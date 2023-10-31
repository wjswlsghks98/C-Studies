#include <iostream>
using namespace std;
//
int main(void)
{
    int h, w, n, m;
    cin >> h >> w >> n >> m;

    cout << ((w-1)/(m+1) + 1) * ((h-1)/(n+1) + 1);

    return 0;
}