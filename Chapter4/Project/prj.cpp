#include <iostream>
#include <cstring>

using namespace std;

const int NAME_LEN = 20;

namespace AccountChoice
{
    enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
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
        
        int getAccID() const
        {
            return accID;
        }

        int getAccBalance() const
        {
            return balance;
        }

        void addMoney(const int &money)
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

class AccountManager
{
    private:
        int accNum;
        Account *accPtr[20];
    public:
        AccountManager()
            : accNum(0)
        {
            //
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

            cout << "[계좌개설]" << endl;
            cout << "계좌ID: "; cin >> id;
            cout << "이름: "; cin >> name;
            cout << "입금액: "; cin >> balance;
            cout << endl;

            accPtr[accNum++] = new Account(id, balance, name);
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

        void ShowAllAccInfo(void)
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




