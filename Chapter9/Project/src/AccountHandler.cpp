#include "AccountHandler.h"
#include <iostream>

using namespace std;

AccountManager::AccountManager() : accNum(0) { }
AccountManager::AccountManager(const AccountManager &copy) : accNum(copy.accNum)
{ 
    for (int i=0;i<accNum;i++)
    {
        accPtr[i] = new Account(*copy.accPtr[i]);
    }
}

void AccountManager::ShowMenu() const
{
    cout << "-----Menu-----" << endl;
    cout << "1. 계좌개설" << endl;
    cout << "2. 입금" << endl;
    cout << "3. 출금" << endl;
    cout << "4. 계좌정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}
void AccountManager::MakeAccount()
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

void AccountManager::DepositMoney()
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

void AccountManager::WithdrawMoney(void)
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

void AccountManager::ShowAllAccInfo(void) const
{
    for (int i=0;i<accNum;i++)
    {
        accPtr[i]->showAccInfo();
    }
}

AccountManager::~AccountManager()
{
    for (int i=0;i<accNum;i++)
    {
        delete accPtr[i];
    }
}