#include <iostream>
#include "Prob2.h"

int main(void)
{
    Printer pnt;
    pnt.SetString("Hello World!");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();
    return 0;
}