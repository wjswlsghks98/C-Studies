#include <iostream>
#include "Prob1.h"
using namespace std;

int main(void)
{
    FruitSeller * sellerPtr = new FruitSeller;
    FruitBuyer * buyerPtr = new FruitBuyer;

    sellerPtr->InitMembers(1000, 20, 0);
    buyerPtr->InitMembers(5000);
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