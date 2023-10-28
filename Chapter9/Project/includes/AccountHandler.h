#ifndef __ACCOUNTHANDLER_H__
#define __ACCOUNTHANDLER_H__

#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "BankingCommonDecl.h"

class AccountManager
{
    private:
        int accNum;
        Account *accPtr[20];
    public:
        AccountManager();
        AccountManager(const AccountManager &copy);
        void ShowMenu() const;
        void MakeAccount();
        void DepositMoney();
        void WithdrawMoney(void);
        void ShowAllAccInfo(void) const;
        ~AccountManager();
};

#endif