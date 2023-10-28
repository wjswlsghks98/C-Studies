#include "StringClass.h"

String::String()
{
    len = 0;
    str = NULL;
}

String::String(const char * s)
{
    len = strlen(s)+1;
    str = new char[len];
    strcpy(str,s);
}

String::String(const String& s)
{
    len = s.len;
    str = new char[len];
    strcpy(str,s.str);
}

String::~String()
{
    if (str!=NULL)
        delete []str;
}

String& String::operator= (const String& s)
{
    if (str!=NULL)
        delete []str;
    len = s.len;
    str = new char[len];
    strcpy(str,s.str);
    return *this;
}

String& String::operator+= (const String& s)
{
    len += (s.len-1);
    char* tmp = new char[len];
    strcpy(tmp,str);
    strcat(tmp,s.str);

    if(str!=NULL)
        delete []str;
    str = tmp;
    return *this;
}

bool String::operator== (const String& s)
{
    return strcmp(str,s.str) ? false : true;
}

String String::operator+ (const String& s)
{
    char* tmp = new char[len+s.len-1];
    strcpy(tmp,str);
    strcat(tmp,s.str);
    String strtmp(tmp);
    delete []tmp;
    return strtmp;
}

int main(void)
{
    String str1 = "I like ";
    String str2 = "string class";
    String str3 = str1 + str2;

    cout << str1 << endl;
    cout << str2 << endl;
    cout << str3 << endl;

    str1 += str2;
    if (str1 == str3)
        cout << "동일 문자열!" << endl;
    else 
        cout << "동일하지 않은 문자열!" << endl;

    String str4;
    cout << "문자열 입력: ";
    cin >> str4;
    cout << "입력한 문자열: " << str4 << endl;
    return 0;
}