#include <iostream>
using namespace std;

class Rectangle
{
    private:
        int width, height;
    public:
        Rectangle(const int &rec_width, const int &rec_height) : width(rec_width), height(rec_height)
        { }
        void ShowAreaInfo() const
        {
            cout << "면적: " << width * height << endl;
        }
};

class Square : public Rectangle
{
    public:
        Square(const int &length) : Rectangle(length, length)
        { }
};

int main(void)
{
    Rectangle rec(4, 3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}