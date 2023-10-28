#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    private:
        char *name;
        int age;
    public:
        Person(char *myname, int myage)
            : age(myage)
        {
            int len = strlen(myname) + 1;
            name = new char[len];
            strcpy(name, myname);
        }
        // Deep Copy 만들기
        Person(const Person &copy)
            : age(copy.age)
        {
            name = new char[strlen(copy.name) + 1]; // Name은 이제 기존 객체의 name을 참조하지 않음.
            strcpy(name,copy.name);
        }

        void ShowPersonInfo() const
        {
            cout << "이름: " << name << endl;
            cout << "나이: " << age << endl;
        }
        ~Person()
        {
            delete []name;
            cout << "Called Destructor" << endl;
        }
};

int main(void)
{
    Person man1("Lee Dong Woo", 29);
    Person man2 = man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}