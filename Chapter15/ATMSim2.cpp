#include <iostream>
#include <cstring>
using namespace std;

class AccountException
{
    public:
        virtual void ShowExceptionReason() =0; // 순수 가상함수.

};

class DepositException : public AccountException
{
    private:
        int reqDep;
    public:
        DepositException(int money) : reqDep(money) {}
        void ShowExceptionReason()
        {
            cout << "[예외 메시지: " << reqDep << "는 입금불가]" << endl;
        }
};

class WithdrawException : public AccountException
{
    private:
        int balance;
    public:
        WithdrawException(int money) : balance(money) {}
        void ShowExceptionReason()
        {
            cout << "[예외 메시지: 잔액 " << balance << ", 잔액부족]" << endl;
        }
};

class Account
{
    private:
        char accNum[50];
        int balance;
    public:
        Account(char * acc, int money) : balance(money)
        {
            strcpy(accNum,acc);
        }

        void Deposit(int money) throw (AccountException)
        {
            if (money <0)
            {
                DepositException expn(money);
                throw expn;
            }
            balance += money;
        }

        void Withdraw(int money) throw (AccountException)
        {
            if (money >= balance)
                throw WithdrawException(balance);
            balance -= money;
        }

        void ShowMyMoney()
        {
            cout << "잔고: " << balance << endl;
        }
};

int main(void)
{
    Account myAcc("56789-827120",5000);
    try 
    {
        myAcc.Deposit(2000);
        myAcc.Deposit(-300);
    }
    catch(AccountException &expn)
    {
        expn.ShowExceptionReason();
    }
    myAcc.ShowMyMoney();

    try
    {
        myAcc.Withdraw(3500);
        myAcc.Withdraw(4000);
    }
    catch(AccountException& expn)
    {
        expn.ShowExceptionReason();
    }
    myAcc.ShowMyMoney();
    return 0;
    
}