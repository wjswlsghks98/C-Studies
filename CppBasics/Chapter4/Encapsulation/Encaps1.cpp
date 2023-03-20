#include <iostream>
using namespace std;

class SinivelCap
{
    public:
        void Take() const
        {
            cout << "Coot Mul Saak" << endl;
        }
};

class SneezeCap
{
    public:
        void Take() const
        {
            cout << "Jae Chae Gi Stop" << endl;
        }
};

class SnuffleCap
{
    public:
        void Take() const
        {
            cout << "Co ga Bbbung" << endl;
        }
};

class ColdPatient
{
    public:
        void TakeSinivelCap(const SinivelCap &cap) const {cap.Take();}
        void TakeSneezeCap(const SneezeCap &cap) const {cap.Take();}
        void TakeSnuffleCap(const SnuffleCap &cap) const {cap.Take();}
};

int main(void)
{
    SinivelCap scap;
    SneezeCap zcap;
    SnuffleCap ncap;

    ColdPatient sufferer;
    sufferer.TakeSinivelCap(scap);
    sufferer.TakeSneezeCap(zcap);
    sufferer.TakeSnuffleCap(ncap);
    return 0;
}