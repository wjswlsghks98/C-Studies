#ifndef __STRING_CLASS_H__
#define __STRING_CLASS_H__

#include <iostream>
#include <cstring>
using namespace std;

class String
{
    private:
        int len;
        char * str;
    public:
        String();
        String(const char * s);
        String(const String& s);
        ~String();
        String& operator= (const String& s);
        String& operator+= (const String& s);
        bool operator== (const String& s);
        String operator+ (const String& s);

        friend ostream& operator<< (ostream& os, const String& s);
        friend istream& operator>> (istream& is, String& s);
};

ostream& operator<< (ostream& os, const String& s)
{
    os << s.str;
    return os;
}

istream& operator>> (istream& is, String& s)
{
    char str[100];
    is >> str;
    s = String(str);
    return is;
}

#endif