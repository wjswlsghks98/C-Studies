#include <iostream>

int main(void){
    int val1, val2;
    int result = 0;
    std::cout << "Input two numbers ";
    std::cin>>val1>>val2;

    if (val1<val2)
    {
        for(int i = val1 + 1; i < val2; i++)
        {
            result += i;
        }
    }
    else
    {
        for (int i = val2 + 1; i < val1; i++)
        {
            result += i;
        }
    }

    std::cout << "Sum of integers between given two numbers: " << result << std::endl;
    return 0;
}