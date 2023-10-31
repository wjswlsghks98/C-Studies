#include <iostream>
#include <string>
#include <vector>
//5073 triangles
using namespace std;

int main(void)
{
    vector<string> sv;

    while(1)
    {
        int num1, num2, num3;
        cin >> num1 >> num2 >> num3;

        if (num1 == 0 && num2 == 0 && num3 == 0)
        {
            for(int i=0; i<sv.size(); i++)
            {
                cout << sv[i] << endl;
            }
            return 0;
        }
        else
        {
            int sum = num1 + num2 + num3;
            int storage[3] = {num1, num2, num3};
            int largest = storage[0];
            for (int i=1; i<3; i++)
            {
                largest = max(largest,storage[i]);
            }
            int rem_sum = sum - largest;

            if (rem_sum <= largest)
                sv.push_back("Invalid");
            else
            {
                if (num1 == num2 && num2 == num3)
                    sv.push_back("Equilateral");
                else if (num1 == num2 || num2 == num3 || num1 == num3)
                    sv.push_back("Isosceles");
                else
                    sv.push_back("Scalene");
            }
        }
    }
}