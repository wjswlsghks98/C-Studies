#include <iostream>

int main(void)
{
    int sum = 0; int var;
    for(int i=1;i<6;i++)
    {
        std::cout << i << "번째 정수 입력: ";
        std::cin >> var;
        sum += var;
    }
    std::cout << "합계: " << sum << std::endl;
    return 0;
}