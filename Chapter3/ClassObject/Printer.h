#ifndef __PRINTER_H__
#define __PRINTER_H__
#include <iostream>

class Printer
{
    private:
        char *str;
    public:
        void SetString(char *input);
        void ShowString(void);
};

inline void Printer::ShowString(void)
{
    std::cout << str << std::endl;
}

#endif