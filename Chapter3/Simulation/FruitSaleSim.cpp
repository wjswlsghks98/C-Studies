#include "FruitSaleSim.h"
#include <iostream>

FruitSeller::FruitSeller(const int &price, const int &num, const int &money)
        : APPLE_PRICE(price), numOfApples(num), myMoney(money)
{
    // Member Initializer:
    // 객체가 아닌 멤버의 초기화도 가능하다.
    // 또한 이니셜라이저를 이용하면 선언과 동시에 초기화가 되기 때문에, const변수를 선언과 동시에 초기화할 수 있다.
    // 위의 APPLE_PRICE는 const 형태로 선언되었음.
}

int FruitSeller::SaleApples(const int & money)
{
    int num = money / APPLE_PRICE;
    numOfApples -= num;
    myMoney += money;
    return num;
}

void FruitSeller::ShowSalesResult(void)
{
    std::cout << "남은 사과: " << numOfApples << std::endl;
    std::cout << "판매 수익: " << myMoney << std::endl << std::endl;
}

FruitBuyer::FruitBuyer(const int &money)
    : numOfApples(0), myMoney(money)
{
    //
}

void FruitBuyer::BuyApples(FruitSeller &seller, const int &money)
{
    if (money < 0)
    {
        std::cout << "구매 금액은 양수이어야 합니다." << std::endl;
        return;
    }
    numOfApples += seller.SaleApples(money); // SaleApples가 const int 형태 이기 때문에 오류 X
    myMoney -= money;
}

void FruitBuyer::ShowBuyResult(void)
{
    std::cout << "현재 잔액: " << myMoney << std::endl;
    std::cout << "사과 개수: " << numOfApples << std::endl << std::endl;
}