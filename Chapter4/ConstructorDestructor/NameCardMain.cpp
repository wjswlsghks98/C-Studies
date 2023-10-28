#include "NameCard.h"

int main(void)
{
    NameCard manCLERK("Lee", "ABCEng", "010-1111-2222", Pos::CLERK);
    NameCard copy1 = manCLERK;
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", Pos::SENIOR);
    NameCard copy2 = manSENIOR;
    NameCard manAssist("Kim", "SoGoodCamp", "010-5555-6666", Pos::ASSIST);
    // manCLERK.ShowNameCardInfo();
    // manSENIOR.ShowNameCardInfo();
    // manAssist.ShowNameCardInfo();
    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();
    return 0;
}