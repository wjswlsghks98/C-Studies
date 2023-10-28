#include <iostream>
#include "AccountHandler.h"

using namespace std;
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