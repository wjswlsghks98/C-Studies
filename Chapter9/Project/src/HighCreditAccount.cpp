#include "HighCreditAccount.h"

HighCreditAccount::HighCreditAccount(const int &ID, const int &money, char *name, const int &ratio, const int &level) : NormalAccount(ID, money, name, ratio)
{
    this->level = level;
}
void HighCreditAccount::addMoney(const int &money)
{
    NormalAccount::addMoney(money);
    Account::addMoney((money * level)/100);
}
HighCreditAccount::~HighCreditAccount()
{
    
}