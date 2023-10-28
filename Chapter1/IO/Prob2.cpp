#include <iostream>

int main(void)
{
    char name[100];
    char pn[100];
    std::cout << "이름 입력: ";
    std::cin >> name;
    std::cout << "전화번호 입력: ";
    std::cin >> pn;

    std::cout << "입력된 이름은 " << name << "입니다" << std::endl;
    std::cout << "입력된 전화번호는 " << pn << "입니다" << std::endl;
    return 0;
}