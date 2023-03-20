#include <iostream>
#include "Prob1.h"
using namespace std;

void FruitSeller::InitMembers(int price, int num, int money)
{
    APPLE_PRICE = price;
    numOfApples = num;
    myMoney = money;
}

int FruitSeller::getApplePrice() const
{
    return APPLE_PRICE;
}

int FruitSeller::getNumOfApples() const
{
    return numOfApples;
}

int FruitSeller::getMyMoney() const
{
    return myMoney;
}

int FruitSeller::SaleApples(int money)
{
    int num = money / APPLE_PRICE;
    numOfApples -= num;
    myMoney += money;
    return num;
}

void FruitSeller::ShowSalesResult()
{
    cout << "Number of apples left: " << numOfApples << endl;
    cout << "Sales result: " << myMoney << endl;
}

void FruitBuyer::InitMembers(int money)
{
    myMoney = money;
    numOfApples = 0;
}

int FruitBuyer::getMyMoney() const
{
    return myMoney;
}

int FruitBuyer::getNumOfApples() const
{
    return numOfApples;
}

void FruitBuyer::BuyApples(FruitSeller * sellerPtr, int money)
{
    if (money < 0) 
    {
        cout << "Input money should be positive" << endl;
        return;
    }
    numOfApples += sellerPtr->SaleApples(money);
    myMoney -= money;
}

void FruitBuyer::ShowBuyResult()
{
    cout << "Money left: " << myMoney << endl;
    cout << "Number of apples: " << numOfApples << endl;
}