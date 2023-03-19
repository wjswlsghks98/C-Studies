#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    char str1[50] = "ABC 123 ";
    char str2[50] = "DEF 456 ";
    char str3[50]; // empty string

    /*
    String Class in std namespace

    string str1 = "ABC 123 ";
    string str2 = "DEF 456 ";

    Many convenient methods can be used

    https://rebro.kr/53
    
    */

    cout << strlen(str1) << endl;
    cout << strlen(str2) << endl;
    strcpy(str3,str1);
    strcat(str3,str2);
    cout << str3 << endl;

    if(strcmp(str1, str2) == 0) cout << "Same String" << endl;
    else cout << "Different String" << endl;
    
    return 0;
}
