#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    private:
        char * name;
    public:
        Person(char * myname)
        {
            name = new char[strlen(myname)+1];
            strcpy(name, myname);
        }
        ~Person()
        {
            delete []name;
        }
        void WhatYourName() const
        {
            cout << "My name is " << name << endl;
        }
};

class UnivStudent : public Person
{
    private:
        char * major;
    public:
        UnivStudent(char *myname, char *mymajor) : Person(myname)
        {
            major = new char[strlen(mymajor)+1];
            strcpy(major, mymajor);
        }
        ~UnivStudent()
        {
            delete []major; // 상속된 univ student class 에서 새롭게 정의한 (동적할당)멤버변수에 대해서만 메모리 해제하면 된다
        }
        void WhoAreYou() const 
        {
            WhatYourName();
            cout << "My major is " << major << endl << endl;
        }
};

int main(void)
{
    UnivStudent st1("Kim", "Mathematics");
    st1.WhoAreYou();
    UnivStudent st2("Hong", "Physics");
    st2.WhoAreYou();
    return 0;
}