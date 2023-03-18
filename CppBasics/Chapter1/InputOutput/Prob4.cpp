#include <iostream>

int calSalary(int pay);

int main(void)
{
    int pay ;

    while(1)
    {
        std::cout << "Input sales money(-1 to end): ";
        std::cin >> pay;

        if(pay == -1) break;
        else
        {
            std::cout << "This month's salary: " << calSalary(pay) << std::endl;
        }
    }
}

int calSalary(int pay)
{
    return int(0.12 * pay + 50);
}