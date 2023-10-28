#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "BankingCommonDecl.h"
#include "AccountArray.h"

class AccountManager
{
    private:
        int accNum;
        BoundCheckAccountPtrArray accArr; // --> 후의 프로젝트를 위헤서 내버려둠.
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