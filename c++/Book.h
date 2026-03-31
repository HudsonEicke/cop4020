//Book.h
#ifndef BOOK_H
#define BOOK_H
#include <string>
class Book
{
    private:
        std::string name;
        double price;
    public:
        Book();
        Book(std::string btitle, double gprice);
        Book(std::string line);

        ~Book();

        std::string getName();
        double getPrice();
        void setName(const std::string newName);
        void setPrice(double newPrice);

        virtual double getRealPrice();
        virtual std::string str();
};
#endif //BOOK_H