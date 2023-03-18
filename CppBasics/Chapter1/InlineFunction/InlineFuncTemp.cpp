#include <iostream>

template <typename T>
inline T Square(T x)
{
    return x * x;
}

int main(void)
{
    std::cout << Square(5.5) << std::endl;
    std::cout << Square(12) << std::endl;
    return 0;
}