#include "CarInline.h"

int main(void)
{
    Car run99;
    run99.InitMembers("run99",100);
    run99.Accel();
    run99.Accel();
    run99.ShowCarState();
    run99.Brake();
    run99.ShowCarState();

    Car sped77;
    sped77.InitMembers("sped77",100);
    sped77.Accel();
    sped77.Brake();
    sped77.ShowCarState();
    return 0;
}