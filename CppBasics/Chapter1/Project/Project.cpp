#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

typedef struct
{
    int id;
    char name[NAME_LEN];
    int balance;
} Account;

Account accArr[100];
int accNum = 0;