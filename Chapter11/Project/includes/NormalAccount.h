#ifndef __NORMALACCOUNT_H__
#define __NORMALACCOUNT_H__

#include "Account.h"

class NormalAccount : public Account
{
    private:
        int ratio;
    public:
        NormalAccount(const int &ID, const int &money, char *name, const int &ratio);
        int getRatio() const;
        virtual void addMoney(const int &money);
        virtual ~NormalAccount();
};

#endif