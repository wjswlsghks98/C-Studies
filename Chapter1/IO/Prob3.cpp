#include <iostream>

int main(void)
{
    int dan;
    std::cout << "단 입력: ";
    std::cin >> dan;

    std::cout << "=====< 제 " << dan << " 단 >=====" << std::endl;
    for(int i=1;i<10;i++)
    {
        std::cout << "      " << dan << " * " << i << " = " << dan * i << std::endl;
    }
    return 0;
}