#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__
#include <iostream>
using namespace std;

class Calculator
{
    private:
        int addNum, subNum, mulNum, divNum;
    public:
        void Init(void);
        void ShowOpCount(void);
        double Add(const double& a, const double &b);
        double Min(const double& a, const double &b);
        double Mul(const double& a, const double &b);
        double Div(const double& a, const double &b);
};

inline void Calculator::ShowOpCount(void)
{
    cout << "덧셈: " << addNum << " 뺄셈: " << subNum << " 곱셈: " << mulNum << " 나눗셈: " << divNum << endl;
}

inline double Calculator::Add(const double& a, const double& b)
{
    addNum++;
    return a + b;
}

inline double Calculator::Min(const double& a, const double& b)
{
    subNum++;
    return a - b;
}

inline double Calculator::Mul(const double& a, const double& b)
{
    mulNum++;
    return a * b;
}

inline double Calculator::Div(const double& a, const double& b)
{
    divNum++;
    return a / b;
}


#endif