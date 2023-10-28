#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
    private:
        char * name;
        int age;
    public:
        MyFriendInfo(char *fname, int fage) : age(fage)
        {
            name = new char[strlen(fname)+1];
            strcpy(name, fname);
        }
        void ShowMyFriendInfo()
        {
            cout << "이름: " << name << endl;
            cout << "나이: " << age << endl;
        }
        ~MyFriendInfo()
        {
            delete []name;
        }
};

class MyFriendDetailInfo : public MyFriendInfo
{
    private:
        char *addr;
        char *phone;
    public:
        MyFriendDetailInfo(char *fname, int fage, char *faddr, char *fphone) : MyFriendInfo(fname, fage)
        {
            addr = new char[strlen(fname)+1];
            phone = new char[strlen(fphone)+1];
            strcpy(addr, faddr);
            strcpy(phone, fphone);
        }
        void ShowMyFriendDetailInfo()
        {
            ShowMyFriendInfo();
            cout << "주소: " << addr << endl;
            cout << "전화: " << phone << endl << endl;
        }
        ~MyFriendDetailInfo()
        {
            delete []addr;
            delete []phone;
        }
};

int main(void)
{
    MyFriendDetailInfo mdfi("Jin",22,"대전광역시","010-9362-9172");
    mdfi.ShowMyFriendDetailInfo();
    return 0;
}