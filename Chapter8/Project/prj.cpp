#include <iostream>
#include <cstring>

using namespace std;

const int NAME_LEN = 20;
// const 는 Chapter6에서 위주로 추가됨. 

namespace AccountChoice
{
    enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
}

namespace AccountCreditLevel
{
    enum {LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2};
}

class Account
{
    private:
        int accID;
        int balance;
        char *cusName;
    public:
        Account(const int &ID, const int &money, char *name)
            : accID(ID), balance(money)
        {
            int len = strlen(name) + 1;
            cusName = new char[len];
            strcpy(cusName,name);
        }
        // Copy Constructor
        Account(const Account &copy)
            : accID(copy.accID), balance(copy.balance)
        {
            cusName = new char[strlen(copy.cusName)+1];
            strcpy(cusName,copy.cusName);
        }
        
        int getAccID() const
        {
            return accID;
        }

        int getAccBalance() const
        {
            return balance;
        }

        virtual void addMoney(const int &money)
        {
            balance += money;
        }

        void showAccInfo() const
        {
            cout << "계좌ID: " << accID << endl;
            cout << "이 름: " << cusName << endl;
            cout << "잔 액: " << balance << endl << endl;
        }

        ~Account()
        {
            delete []cusName;
        }
};

class NormalAccount : public Account
{
    private:
        int ratio;
    public:
        NormalAccount(const int &ID, const int &money, char *name, const int &ratio) : Account(ID,money,name)
        {
            this->ratio = ratio;
        }
        int getRatio() const { return ratio; }
        virtual void addMoney(const int &money)
        {
            Account::addMoney(money);
            Account::addMoney((money * ratio) / 100);
        }
};

class HighCreditAccount : public NormalAccount
{
    private:
        int level;
    public:
        HighCreditAccount(const int &ID, const int &money, char *name, const int &ratio, const int &level) : NormalAccount(ID, money, name, ratio)
        {
            this->level = level;
        }
        virtual void addMoney(const int &money)
        {
            NormalAccount::addMoney(money);
            Account::addMoney((money * level)/100);
        }
};  


class AccountManager
{
    private:
        int accNum;
        Account *accPtr[20];
    public:
        AccountManager() : accNum(0)
        { }
        AccountManager(const AccountManager &copy) : accNum(copy.accNum)
        { 
            for (int i=0;i<accNum;i++)
            {
                accPtr[i] = new Account(*copy.accPtr[i]);
            }
        }

        void ShowMenu() const
        {
            cout << "-----Menu-----" << endl;
            cout << "1. 계좌개설" << endl;
            cout << "2. 입금" << endl;
            cout << "3. 출금" << endl;
            cout << "4. 계좌정보 전체 출력" << endl;
            cout << "5. 프로그램 종료" << endl;
        }
        void MakeAccount()
        {
            int id;
            char name[NAME_LEN];
            int balance;
            int account_type;
            int ratio; // 이율
            cout << "[계좌종류선택]" << endl;
            cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
            cout << "선택: "; cin >> account_type;


            cout << "[보통예금계좌개설]" << endl;
            cout << "계좌ID: "; cin >> id;
            cout << "이름: "; cin >> name;
            cout << "입금액: "; cin >> balance;
            cout << "이자율: "; cin >> ratio; 

            if (account_type == 2)
            {
                int level;
                cout << "신용등급(1toA, 2toB, 3toC): "; cin >> level;
                cout << endl;
                switch(level)
                {
                    case 1:
                        accPtr[accNum++] = new HighCreditAccount(id, balance, name,ratio,AccountCreditLevel::LEVEL_A);
                        break;
                    case 2:
                        accPtr[accNum++] = new HighCreditAccount(id, balance, name,ratio,AccountCreditLevel::LEVEL_B);
                        break;
                    case 3:
                        accPtr[accNum++] = new HighCreditAccount(id, balance, name,ratio,AccountCreditLevel::LEVEL_C);
                        break;
                    default:
                        cout << "Illegal Selection..." << endl; 
                        break;
                }
                
            }
            else if (account_type == 1)
            {
                cout << endl;
                accPtr[accNum++] = new NormalAccount(id, balance, name,ratio);
            }
            
        }

        void DepositMoney()
        {
            int money, id;
            cout << "[입 금]" << endl;
            cout << "계좌ID: "; cin >> id;
            cout << "입금액: "; cin >> money;

            for (int i=0;i<accNum;i++)
            {
                if (accPtr[i]->getAccID() == id)
                {
                    accPtr[i]->addMoney(money);
                    cout << "입금완료" << endl << endl;
                    return;
                }
            }
            cout << "유효하지 않은 ID 입니다." << endl << endl;
        }

        void WithdrawMoney(void)
        {
            int money, id;
            cout << "[출 금]" << endl;
            cout << "계좌ID: "; cin >> id;
            cout << "출금액: "; cin >> money;

            for (int i=0;i<accNum;i++)
            {
                if (accPtr[i]->getAccID() == id)
                {
                    if (accPtr[i]->getAccBalance() < money)
                    {
                        cout << "잔액부족" << endl;
                        return;
                    }
                    accPtr[i]->addMoney(-money);
                    cout << "출금완료" << endl << endl;
                    return;
                }
            }
            cout << "유효하지 않은 ID 입니다." << endl << endl;
        }

        void ShowAllAccInfo(void) const
        {
            for (int i=0;i<accNum;i++)
            {
                accPtr[i]->showAccInfo();
            }
        }

        ~AccountManager()
        {
            for (int i=0;i<accNum;i++)
            {
                delete accPtr[i];
            }
        }
};

int main(void)
{
    AccountManager accounts;
    int choice;
    
    while(1)
    {
        accounts.ShowMenu();
        cout << "선택: ";
        cin >> choice;
        cout << endl;

        switch(choice)
        {
            case AccountChoice::MAKE:
                accounts.MakeAccount();
                break;
            
            case AccountChoice::DEPOSIT:
                accounts.DepositMoney();
                break;

            case AccountChoice::WITHDRAW:
                accounts.WithdrawMoney();
                break;

            case AccountChoice::INQUIRE:
                accounts.ShowAllAccInfo();
                break;

            case AccountChoice::EXIT:
                return 0;

            default:
                cout << "Illegal Selection.." << endl;
        }
    }
    return 0;
}




