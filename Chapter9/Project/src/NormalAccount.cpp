#include "NormalAccount.h"

NormalAccount::NormalAccount(const int &ID, const int &money, char *name, const int &ratio) : Account(ID,money,name)
{
    this->ratio = ratio;
}
int NormalAccount::getRatio() const { return ratio; }
void NormalAccount::addMoney(const int &money)
{
    Account::addMoney(money);
    Account::addMoney((money * ratio) / 100);
}

NormalAccount::~NormalAccount()
{
    
}