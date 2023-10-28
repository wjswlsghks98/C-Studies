#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account
{
    private:
        int accID;
        int balance;
        char *cusName;
    public:
        Account(const int &ID, const int &money, char *name);
        Account(const Account &copy); // Copy Constructor
        Account& operator=(const Account& copy);
        int getAccID() const;
        int getAccBalance() const;
        virtual void addMoney(const int &money);
        void showAccInfo() const;
        virtual ~Account();
};

#endif