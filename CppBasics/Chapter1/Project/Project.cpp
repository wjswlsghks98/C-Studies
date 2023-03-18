#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct
{
    int id;
    char name[NAME_LEN];
    int balance;
} Account;

Account accArr[100];
int accNum = 0;

int main(void)
{
    int choice = 0;

    while(1)
    {
        ShowMenu();
        cout << "Choice: "; cin >> choice;

        switch(choice)
        {
            case MAKE:
                MakeAccount();
                break;
            case DEPOSIT:
                DepositMoney();
                break;
            case WITHDRAW:
                WithdrawMoney();
                break;
            case INQUIRE:
                ShowAllAccInfo();
                break;
            case EXIT:
                return 0;
            default:
                cout << "Invalid Input" << endl << endl;
                break;
        }
    }

}

void ShowMenu(void)
{
    cout << "-----Menu-----" << endl;
    cout << MAKE << ". Make New Account" << endl;
    cout << DEPOSIT << ". Deposit" << endl;
    cout << WITHDRAW << ". Withdraw" << endl;
    cout << INQUIRE << ". Inquire" << endl;
    cout << EXIT << ". Exit" << endl;
}

void MakeAccount(void)
{
    int id; 
    char name[NAME_LEN];
    int balance;

    cout << "[Make Account]" << endl;
    cout << "Account ID: "; cin >> id;
    cout << "Name: "; cin >> name;
    cout << "Deposit: "; cin >> balance;
    cout << endl;

    accArr[accNum].id = id;
    strcpy(accArr[accNum].name, name);
    accArr[accNum].balance = balance;
    accNum++;
}

void DepositMoney(void)
{
    int id, money;
    cout << "[Deposit Money]" << endl;
    cout << "Account ID: "; cin >> id;

    for(int i=0; i<accNum; i++)
    {
        if(accArr[i].id == id)
        {
            cout << "Deposit Amount: "; cin >> money;
            accArr[i].balance += money;
            cout << "Deposit Finished" << endl <<endl;
            return;
        }
    }
    cout << "Invalid ID" << endl << endl;
}

void WithdrawMoney(void)
{
    int id, money;
    cout << "[Withdraw Money]" << endl;
    cout << "Account ID: "; cin >> id;

    for(int i=0; i<accNum; i++)
    {
        if(accArr[i].id == id)
        {
            cout << "Withdraw Amount: "; cin >> money;
            if(accArr[i].balance - money < 0)
            {
                cout << "Not Enough Money Left" << endl << endl;
                return;
            }
            else
            {
                accArr[i].balance -= money;
                cout << "Account Balance: " << accArr[i].balance << endl;
                cout << "Withdraw Finished" << endl << endl;
                return;
            }
        }
    }
    cout << "Invalid ID" << endl << endl;
}

void ShowAllAccInfo(void)
{
    for(int i=0; i<accNum; i++)
    {
        cout << endl;
        cout << "Account ID: " << accArr[i].id << endl;
        cout << "Name: " << accArr[i].name << endl;
        cout << "Balance: " << accArr[i].balance << endl << endl;
    }
}