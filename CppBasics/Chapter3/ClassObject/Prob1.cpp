#include "Prob1.h"
#include <iostream>
using namespace std;

void Calculator::Init()
{
    for(int i=0;i<4;i++)
    {
        counter[i] = 0;
    }  
}

double Calculator::Add(double num1, double num2)
{
    counter[CAL_FORMAT::ADD]++;
    return num1 + num2;
}

double Calculator::Min(double num1, double num2)
{
    counter[CAL_FORMAT::SUB]++;
    return num1 - num2;
}

double Calculator::Mul(double num1, double num2)
{
    counter[CAL_FORMAT::MUL]++;
    return num1 * num2;
}

double Calculator::Div(double num1, double num2)
{
    counter[CAL_FORMAT::DIV]++;
    return num1 / num2;
}

void Calculator::ShowOpCount()
{
    cout << "Addition: " << counter[CAL_FORMAT::ADD];
    cout << "  Subtraction: " << counter[CAL_FORMAT::SUB];
    cout << "  Multiplication: " << counter[CAL_FORMAT::MUL];
    cout << "  Division: " << counter[CAL_FORMAT::DIV] << endl;
}
