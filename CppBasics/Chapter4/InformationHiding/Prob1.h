class FruitSeller
{
    private:
        int APPLE_PRICE;
        int numOfApples;
        int myMoney;
    public:
        void InitMembers(int price, int num, int money);
        int getApplePrice() const;
        int getNumOfApples() const;
        int getMyMoney() const;
        int SaleApples(int money);
        void ShowSalesResult();
};

class FruitBuyer
{
    private:
        int myMoney;
        int numOfApples;
    public:
        void InitMembers(int money);
        int getMyMoney() const;
        int getNumOfApples() const;
        void BuyApples(FruitSeller * sellerPtr, int money);
        void ShowBuyResult();
};