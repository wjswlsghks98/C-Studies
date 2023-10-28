#include "Account.h"
#include <cstring>
#include <iostream>
using namespace std;

Account::Account(const int &ID, const int &money, char *name) : accID(ID), balance(money)
{
    int len = strlen(name) + 1;
    cusName = new char[len];
    strcpy(cusName,name);
}

// Copy Constructor
Account::Account(const Account &copy) : accID(copy.accID), balance(copy.balance)
{
    cusName = new char[strlen(copy.cusName)+1];
    strcpy(cusName,copy.cusName);
}

// operator
Account& Account::operator=(const Account& copy)
{
    accID = copy.accID;
    balance = copy.balance;
    delete []cusName;
    cusName = new char[strlen(copy.cusName)+1];
    strcpy(cusName, copy.cusName);
    return *this;
}
        
int Account::getAccID() const { return accID; }

int Account::getAccBalance() const { return balance; }

void Account::addMoney(const int &money) { balance += money; }

void Account::showAccInfo() const
{
    cout << "계좌ID: " << accID << endl;
    cout << "이 름: " << cusName << endl;
    cout << "잔 액: " << balance << endl << endl;
}

Account::~Account() { delete []cusName; }