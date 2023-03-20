#include "Prob2.h"
#include <iostream>
#include <cstring>
using namespace std;

void Printer::SetString(char * inputStr)
{
    strcpy(Str,inputStr);
}

void Printer::ShowString()
{
    cout << Str << endl;
}

