//Defines all of the Book class functions
#include "Book.h"
#include <iostream>
#include <sstream>

//Default constructor for Book class sets name = "" and price = 100
Book::Book()
{
    name = "";
    price = 100;
}

//Constructor for Book class that uses btitle and gprice parameters to set name and price btitle is the title of the book and gprice is the price of the book
Book::Book(std::string btitle, double gprice)
{
    this->name = btitle;
    this->price = gprice;
}

//Constructor for Book class that uses a book line and splits it to set name and price correctly line is a book line in the format b somebooktitle someprice
Book::Book(std::string line)
{
    std::istringstream iss(line);
    std::string word;

    iss >> word;
    iss >> this->name;
    iss >> word;
    this->price = std::stod(word);
}

//Destructor for Book class that does nothing
Book::~Book()
{

}

//Returns the name of the book to the caller
std::string Book::getName()
{
    return name;
}

//Returns the price of the book to the caller
double Book::getPrice()
{
    return price;
}

//Sets the name of the book to the newName newName is a string that is a new title of a book
void Book::setName(const std::string newName)
{
    name = newName;
}

//Sets the price of the book to the newPrice newPrice is a double that is the new price of a book
void Book::setPrice(double newPrice)
{
    price = newPrice;
}


//Virtual method that gets the real price of the book by multiplying the price of the book by 0.8
double Book::getRealPrice()
{
    return price * 0.8;
}

//Virtual method that returns a string for the book in the format Literature Book:<name> price:<realPrice>
std::string Book::str()
{
    std::string result = "Literature Book:";

    result.append(name);
    result.append(" price:");
    result.append(std::to_string(getRealPrice()));

    return result;
}