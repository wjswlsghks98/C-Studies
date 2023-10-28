#ifndef __HIGHCREDITACCOUNT_H__
#define __HIGHCREDITACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount
{
    private:
        int level;
    public:
        HighCreditAccount(const int &ID, const int &money, char *name, const int &ratio, const int &level);
        virtual void addMoney(const int &money);
        virtual ~HighCreditAccount();
};

#endif