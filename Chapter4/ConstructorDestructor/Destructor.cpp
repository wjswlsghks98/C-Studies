#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    private:
        char * name;
        int age;
    public:
        Person(char *myname, const int &myage)
            : age(myage)
        {
            int len = strlen(myname) + 1;
            name = new char[len];
            strcpy(name, myname);
        }

        void ShowPersonInfo() const
        {
            cout << "이름: " << name << endl;
            cout << "나이: " << age << endl;
        }

        ~Person()
        {
            delete []name;
            cout << "Called Destructor!" << endl;
        }
};

int main(void)
{
    Person man1("Lee Dong Woo", 29);
    Person man2("Jang Dong Gun", 41);
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}