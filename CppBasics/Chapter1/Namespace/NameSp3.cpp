#include <iostream>

namespace BestComImpl
{
    void SimpleFunc(void);
    void PrettyFunc(void);
}

namespace ProgComImpl
{
    void SimpleFunc(void);
}

int main(void)
{
    BestComImpl::SimpleFunc();
    return 0;
}

void BestComImpl::SimpleFunc(void)
{
    std::cout << "Function defined by BestCom" << std::endl;
    PrettyFunc(); // Function within the same namespace can be called without BestComImpl::
    ProgComImpl::SimpleFunc(); // Function not within the same namespace have to be called differently.
}

void BestComImpl::PrettyFunc(void)
{
    std::cout << "So Pretty!!" << std::endl;
}

void ProgComImpl::SimpleFunc(void)
{
    std::cout << "Function defined by ProgCom" << std::endl;
}