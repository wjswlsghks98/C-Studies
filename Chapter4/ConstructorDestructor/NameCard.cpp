#include <iostream>
#include <cstring>
#include "NameCard.h"

void Pos::ShowPosition(const int &pos)
{
    switch(pos)
    {
        case CLERK:
            std::cout << "직급: 사원" << std::endl << std::endl;
            break;
        case SENIOR:
            std::cout << "직급: 주임" << std::endl << std::endl;
            break;
        case ASSIST:
            std::cout << "직급: 대리" << std::endl << std::endl;
            break;
        case MANAGER:
            std::cout << "직급: 과장" << std::endl << std::endl;
            break;
    }
}

NameCard::NameCard(char *name_, char *company_, char *pn_, const int &position_)
    : position(position_)
{
    int name_len = strlen(name_) + 1;
    int comp_len = strlen(company_) + 1;
    int pn_len = strlen(pn_) + 1;

    name = new char[name_len];
    company = new char[comp_len];
    pn = new char[pn_len];

    strcpy(name,name_);
    strcpy(company,company_);
    strcpy(pn,pn_);
}

// For Deep Copy in Chapter 5
NameCard::NameCard(const NameCard &copy)
    : position(copy.position)
{
    name = new char[strlen(copy.name)+1];
    company = new char[strlen(copy.company)+1];
    pn = new char[strlen(copy.pn)+1];

    strcpy(name,copy.name);
    strcpy(company,copy.company);
    strcpy(pn,copy.pn);
}

void NameCard::ShowNameCardInfo() const
{
    std::cout << "이름: " << name << std::endl;
    std::cout << "회사: " << company << std::endl;
    std::cout << "전화번호: " << pn << std::endl;
    Pos::ShowPosition(position);

}

NameCard::~NameCard()
{
    delete []name;
    delete []company;
    delete []pn;
}