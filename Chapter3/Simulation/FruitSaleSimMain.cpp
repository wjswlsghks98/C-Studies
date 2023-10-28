#include "FruitSaleSim.h"
#include <iostream>

int main(void)
{
    FruitSeller seller(1000, 20, 0); 
    FruitBuyer buyer(5000);
    buyer.BuyApples(seller, 2000);

    std::cout << "과일 판매자 현황" << std::endl;
    seller.ShowSalesResult();
    
    std::cout << "과일 구매자 현황" << std::endl;
    buyer.ShowBuyResult();
    return 0;
}