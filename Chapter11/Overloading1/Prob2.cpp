#include <iostream>
#include <cstring>
using namespace std;

class Book
{
    private:
        char * title;
        char * isbn;
        int price;
    public:
        Book(char *title, char *isbn, int value) : price(value)
        {
            this->title = new char[strlen(title)+1];
            this->isbn = new char[strlen(isbn)+1];
            strcpy(this->title, title);
            strcpy(this->isbn, isbn);
        }
        Book(const Book& ref) : price(ref.price)
        {
            title = new char[strlen(ref.title)+1];
            isbn = new char[strlen(ref.isbn)+1];
            strcpy(title,ref.title);
            strcpy(isbn,ref.isbn);
        }
        Book& operator=(const Book& ref)
        {
            delete []title;
            delete []isbn;
            title = new char[strlen(ref.title)+1];
            isbn = new char[strlen(ref.isbn)+1];
            strcpy(title,ref.title);
            strcpy(isbn,ref.isbn);
            price = ref.price;

            return *this;
        }
        void ShowBookInfo() const
        {
            cout << "제목: " << title << endl;
            cout << "ISBN: " << isbn << endl;
            cout << "가격: " << price << endl;
        }
        ~Book()
        {
            delete []title;
            delete []isbn;
        }
};

class EBook : public Book
{
    private:
        char * DRMKey;
    public:
        EBook(char *title, char *isbn, int value, char * DRMKey) : Book(title, isbn, value)
        {
            this->DRMKey = new char[strlen(DRMKey)+1];
            strcpy(this->DRMKey, DRMKey);
        }
        EBook(const EBook& ref) : Book(ref) // Book의 복사 생성자 호출!
        {
            DRMKey = new char[strlen(ref.DRMKey)+1];
            strcpy(DRMKey,ref.DRMKey);
        }
        EBook& operator=(const EBook& ref)
        {
            Book::operator=(ref);
            delete []DRMKey;
            DRMKey = new char[strlen(ref.DRMKey)+1];
            strcpy(DRMKey,ref.DRMKey);
            return *this;
        }
        void ShowEBookInfo() const
        {
            ShowBookInfo();
            cout << "인증키: " << DRMKey << endl;
        }
        ~EBook()
        {
            delete []DRMKey;
        }
};

int main(void)
{
    EBook ebook1("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    EBook ebook2 = ebook1; // 복사 생성자 호출
    ebook2.ShowBookInfo();
    cout << endl;
    EBook ebook3("dummy","dummy",0,"dummy");
    ebook3 = ebook2;
    ebook3.ShowBookInfo();
    return 0;
}