#ifndef __NAMECARD_H__
#define __NAMECARD_H__


namespace Pos
{
    enum 
    {
        CLERK, SENIOR, ASSIST, MANAGER
    };

    void ShowPosition(const int &pos);
}

class NameCard
{
    private:
        char *name;
        char *company;
        char *pn;
        int position;
    public:
        NameCard(char *name_, char *company_, char *pn_, const int &position_);
        NameCard(const NameCard &copy);
        void ShowNameCardInfo() const;
        ~NameCard();
};

#endif