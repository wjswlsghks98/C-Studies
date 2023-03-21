class FruitSeller
{
    private:
        int APPLE_PRICE;
        int numOfApples;
        int myMoney;
    public:
        FruitSeller(int price, int num, int money);
        int SaleApples(int money);
        void ShowSalesResult();
};

class FruitBuyer
{
    private:
        int myMoney;
        int numOfApples;
    public:
        FruitBuyer(int money);
        void BuyApples(FruitSeller * sellerPtr, int money);
        void ShowBuyResult();
};