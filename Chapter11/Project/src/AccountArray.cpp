#include "BankingCommonDecl.h"
#include "AccountArray.h"

BoundCheckAccountPtrArray::BoundCheckAccountPtrArray(int len) : arrlen(len)
{
    arr = new ACCOUNT_PTR[arrlen]; // 각 account의 위치를 저장하고 있는 포인터 배열의 주소.
}

ACCOUNT_PTR& BoundCheckAccountPtrArray::operator[] (int idx)
{   
    if (idx < 0 || idx >= arrlen)
    {
        cout << "Array index out of bound exception" << endl;
        exit(1);
    }
    return arr[idx];
}

ACCOUNT_PTR BoundCheckAccountPtrArray::operator[] (int idx) const
{
    if (idx < 0 || idx >= arrlen)
    {
        cout << "Array index out of bound exception" << endl;
        exit(1);
    }
    return arr[idx];
}

int BoundCheckAccountPtrArray::GetArrLen() const
{
    return arrlen;
}

BoundCheckAccountPtrArray::~BoundCheckAccountPtrArray()
{
    delete []arr;
}