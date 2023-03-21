#include <iostream>
#include "FruitSaleSim2.h"
using namespace std;

int main(void)
{
    FruitSeller * sellerPtr = new FruitSeller(1000, 20, 0);
    FruitBuyer * buyerPtr = new FruitBuyer(5000);

    buyerPtr->BuyApples(sellerPtr, 2000);

    cout << "[Apple Seller Status]" << endl;
    sellerPtr->ShowSalesResult();
    cout << endl;
    cout << "[Apple Buyer Status]" << endl;
    buyerPtr->ShowBuyResult();

    delete sellerPtr;
    delete buyerPtr;
    return 0;
}