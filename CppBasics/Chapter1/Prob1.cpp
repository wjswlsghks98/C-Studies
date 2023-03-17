#include <iostream>

int main(void)
{
    int values[5];
    int sum = 0;
    for (int i=0; i<5; i++)
    {
        std::cout << i+1 << "th number input: ";
        std::cin >> values[i];
        sum += values[i];
    }
    std::cout << "Total sum : " << sum;
}