#include "BankingSystemVer02.h"
#include <iostream>
using namespace std;

Account *accArr[100];
int accNum = 0;

int main(void)
{
    int choice;

    while(1)
    {
        ShowMenu();
        cout << "Choice: ";
        cin >> choice;
        cout << endl;

        switch(choice)
        {
            case AccountOptions::MAKE:
                MakeAccount(accArr,accNum);
                break;
            case AccountOptions::DEPOSIT:
                DepositMoney(accArr,accNum);
                break;
            case AccountOptions::WITHDRAW:
                WithdrawMoney(accArr,accNum);
                break;
            case AccountOptions::INQUIRE:
                ShowAllAccInfo(accArr,accNum);
                break;
            case AccountOptions::EXIT:
                return 0;
            default:
                cout << "Illegal Selection" << endl << endl;
        }
    }

    for(int i=0;i<=accNum;i++)
    {
        delete accArr[i];
    }

    return 0;
}