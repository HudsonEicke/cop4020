//Declares the Book class and defines the instance variables
#ifndef BOOK_H
#define BOOK_H
#include <string>
class Book
{
    private:
        std::string name;
        double price;
    public:
        //Default constructor for Book class sets name = "" and price = 100
        Book();
        //Constructor for Book class that uses btitle and gprice parameters to set name and price btitle is the title of the book and gprice is the price of the book
        Book(std::string btitle, double gprice);
        //Constructor for Book class that uses a book line and splits it to set name and price correctly line is a book line in the format b somebooktitle someprice
        Book(std::string line);

        //Destructor for Book class that does nothing
        virtual ~Book();

        //Returns the name of the book to the caller
        std::string getName();
        //Returns the price of the book to the caller
        double getPrice();
        //Sets the name of the book to the newName newName is a string that is a new title of a book
        void setName(const std::string newName);
        //Sets the price of the book to the newPrice newPrice is a double that is the new price of a book
        void setPrice(double newPrice);

        //Virtual method that gets the real price of the book by multiplying the price of the book by 0.8
        virtual double getRealPrice();
        //Virtual method that returns a string for the book in the format Literature Book:<name> price:<realPrice>
        virtual std::string str();
};
#endif