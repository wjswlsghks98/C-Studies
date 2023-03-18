#include <iostream>

int main(void)
{
    int dan;
    std::cout << "Input dan number: ";
    std::cin >> dan;
    std::cout << dan << " dan" << std::endl;
    for (int i=1; i< 10; i++)
    {   
        std::cout << dan << " X " << i << " = " << dan * i << std::endl;
    }
}