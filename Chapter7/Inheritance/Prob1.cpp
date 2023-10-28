#include <iostream>
using namespace std;

class Car
{
    private:
        int gasolineGauge;
    public:
        Car(const int &gasolineGauge)
        {
            this->gasolineGauge = gasolineGauge;
        }
        int GetGasGauge() const
        {
            return gasolineGauge;
        }
};

class HybridCar : public Car
{
    private:
        int electricGauge;
    public:
        HybridCar(const int &gasolineGauge, const int &electricGauge) : Car(gasolineGauge)
        {
            this->electricGauge = electricGauge;
        }
        int GetElecGauge() const
        {
            return electricGauge;
        }
};

class HybridWaterCar : public HybridCar
{
    private:
        int waterGauge;
    public:
        HybridWaterCar(const int &gasolineGauge, const int &electricGauge, const int &waterGauge) : HybridCar(gasolineGauge, electricGauge)
        {
            this->waterGauge = waterGauge;
        }
        void ShowCurrentGauge()
        {
            cout << "잔여 가솔린: " << GetGasGauge() << endl;
            cout << "잔여 전기량: " << GetElecGauge() << endl;
            cout << "잔여 워터량: " << waterGauge << endl;
        }
};

int main(void)
{
    HybridWaterCar hyb1(100,20,10);
    hyb1.ShowCurrentGauge();
    return 0;
}