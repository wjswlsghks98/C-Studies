#ifndef __FRUITSALESIM_H__
#define __FRUITSALESIM_H__

class FruitSeller
{
    private:
        const int APPLE_PRICE;
        int numOfApples;
        int myMoney;
    public:
        FruitSeller(const int &price, const int &num, const int &money);
        int SaleApples(const int &money);
        void ShowSalesResult(void);
};

class FruitBuyer
{
    private:
        int myMoney;
        int numOfApples;
    public:
    FruitBuyer(const int &money); // Chapter4에서 Constructor 공부한 후, 수정하였음.
    void BuyApples(FruitSeller &seller, const int &money);
    void ShowBuyResult(void);
};


#endif