#ifndef __PROB2_H__
#define __PROB2_H__

#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
    enum {CLERK, SENIOR, ASSIST, MANAGER};

    void ShowPositionInfo(int pos)
    {
        switch(pos)
        {
            case CLERK:
                cout << "Position: Clerk" << endl << endl;
                break;
            case SENIOR:
                cout << "Position: Senior" << endl << endl;
                break;
            case ASSIST:
                cout << "Position: Assist" << endl << endl;
                break;
            case MANAGER:
                cout << "Position: Manager" << endl << endl;
                break;
        }
    }
}

class NameCard
{
    private:
        char * Name;
        char * CompanyName;
        char * PhoneNum;
        int position;
        
    public:
        NameCard(char * name, char * companyname, char * phonenum, int pos)
            : position(pos)
        {
            int name_len = strlen(name) + 1;
            int companyname_len = strlen(companyname) + 1;
            int phonenum_len = strlen(phonenum) + 1;

            Name = new char[name_len];
            CompanyName = new char[companyname_len];
            PhoneNum = new char[phonenum_len];

            strcpy(Name,name);
            strcpy(CompanyName,companyname);
            strcpy(PhoneNum,phonenum);
        }
        void ShowNameCardInfo()
        {
            cout << "Name: " << Name << endl;
            cout << "Company: " << CompanyName << endl;
            cout << "Phone Number: " << PhoneNum << endl;
            COMP_POS::ShowPositionInfo(position);
        }
        ~NameCard()
        {
            delete []Name;
            delete []CompanyName;
            delete []PhoneNum;
        }
};

#endif