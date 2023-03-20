#include <iostream>
#include "FruitSaleSim1.h"
using namespace std;

void FruitSeller::InitMembers(int price, int num, int money)
{
    APPLE_PRICE = price;
    numOfApples = num;
    myMoney = money;
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

void FruitBuyer::BuyApples(FruitSeller * sellerPtr, int money)
{
    numOfApples += sellerPtr->SaleApples(money);
    myMoney -= money;
}

void FruitBuyer::ShowBuyResult()
{
    cout << "Money left: " << myMoney << endl;
    cout << "Number of apples: " << numOfApples << endl;
}