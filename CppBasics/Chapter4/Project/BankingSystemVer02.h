#ifndef __BANKINGSYSTEMVER02_H__
#define __BANKINGSYSTEMVER02_H__

#include <iostream>
#include <cstring>

namespace AccountOptions 
{
    enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
}

class Account
{
    private:
        int accID, balance;
        char * cusName;
    public:
        Account(int ID, int Money, char * Name);
        void Deposit(int Money);
        void Withdraw(int Money);
        void AccInfo(void) const;
        int getID(void) const;
        ~Account();
};

void ShowMenu(void);
void MakeAccount(Account * AccountPtrs[], int &accNumRef);
void DepositMoney(Account * AccountPtrs[], const int &accNumRef);
void WithdrawMoney(Account * AccountPtrs[], const int &accNumRef);
void ShowAllAccInfo(Account * AccountPtrs[], const int &accNumRef);

#endif