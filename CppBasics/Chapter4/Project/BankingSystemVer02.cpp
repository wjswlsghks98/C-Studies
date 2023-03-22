#include "BankingSystemVer02.h"
#include <iostream>
#include <cstring>
using namespace std;

int name_len = 20;

Account::Account(int ID, int Money, char * Name) : accID(ID), balance(Money)
{
    cusName = new char[strlen(Name) + 1];
    strcpy(cusName,Name);
}

void Account::Deposit(int Money)
{
    if(Money < 0) cout << "Input money cannot be negative value" << endl << endl;
    else 
    {
        balance += Money;
        cout << "Deposit Complete" << endl << endl;
    }
}

void Account::Withdraw(int Money)
{
    if(balance - Money < 0) cout << "Not enough money to withdraw" << endl << endl;
    else 
    {
        balance -= Money;
        cout << "Withdraw Complete" << endl << endl;
    }
}

void Account::AccInfo(void) const
{
    cout << "Account ID: " << accID << endl;
    cout << "Name: " << cusName << endl;
    cout << "Balance: " << balance << endl << endl;
}

int Account::getID(void) const
{
    return accID;
}

Account::~Account()
{
    delete []cusName;
}

void ShowMenu(void)
{
    cout << "-----Menu-----" << endl;
    cout << "1. Create Account" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Show All Account Information" << endl;
    cout << "5. Exit" << endl;
}

void MakeAccount(Account * AccountPtr[], int &accNumRef)
{
    int ID, Money;
    char Name[name_len];
    cout << "[Create New Account]" << endl;
    cout << "ID: "; cin >> ID;
    cout << "Name: "; cin >> Name;
    cout << "Deposit Money: "; cin >> Money;

    AccountPtr[accNumRef] = new Account(ID, Money, Name);
    accNumRef++;
    cout << endl;
}

void DepositMoney(Account * AccountPtrs[], const int &accNumRef)
{
    int ID, Money;
    cout << "[Deposit Money]" << endl;
    cout << "Account ID: ";
    cin >> ID;

    for(int i=0;i<accNumRef;i++)
    {
        if(AccountPtrs[i]->getID() == ID) 
        {
            cout << "Deposit Money: ";
            cin >> Money;
            AccountPtrs[i]->Deposit(Money);            
            return;
        }
    }
    cout << "There is no ID that matches the input" << endl << endl;   
}

void WithdrawMoney(Account * AccountPtrs[], const int &accNumRef)
{
    int ID, Money;
    cout << "[Withdraw Money]" << endl;
    cout << "Account ID: ";
    cin >> ID;

    for(int i=0;i<accNumRef;i++)
    {
        if(AccountPtrs[i]->getID() == ID) 
        {
            cout << "Withdraw Money: ";
            cin >> Money;
            AccountPtrs[i]->Withdraw(Money);            
            return;
        }
    }
    cout << "There is no ID that matches the input" << endl << endl;   
}

void ShowAllAccInfo(Account * AccountPtrs[], const int &accNumRef)
{
    for(int i=0;i<accNumRef;i++)
    {
        AccountPtrs[i]->AccInfo(); 
    }
}