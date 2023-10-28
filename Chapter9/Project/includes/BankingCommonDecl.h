#ifndef __BANKINGCOMMONDECL_H__
#define __BANKINGCOMMONDECL_H__

const int NAME_LEN = 20;
// const 는 Chapter6에서 위주로 추가됨. 

namespace AccountChoice
{
    enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
}

namespace AccountCreditLevel
{
    enum {LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2};
}

#endif