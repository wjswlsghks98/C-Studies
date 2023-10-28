#include <iostream>

template <typename T>
inline T SQUARE(T x);

int main(void)
{
    std::cout << SQUARE(5) << std::endl;
    std::cout << SQUARE(12.5) << std::endl;
    return 0;
}

template <typename T>
inline T SQUARE(T x)
{
    return x * x;
}