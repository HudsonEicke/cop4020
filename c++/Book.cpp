#include "Book.h"
#include <iostream>
#include <sstream>

Book::Book()
{
    name = "";
    price = 100;
}

Book::Book(std::string btitle, double gprice)
{
    this->name = btitle;
    this->price = gprice;
}

Book::Book(std::string line)
{
    std::istringstream iss(line);
    std::string word;

    iss >> word;
    iss >> this->name;
    iss >> word;
    this->price = std::stod(word);
}

Book::~Book()
{

}

std::string Book::getName()
{
    return name;
}

double Book::getPrice()
{
    return price;
}

void Book::setName(const std::string newName)
{
    name = newName;
}

void Book::setPrice(double newPrice)
{
    price = newPrice;
}

double Book::getRealPrice()
{
    return price * 0.8;
}

std::string Book::str()
{
    std::string result = "Literature Book:";

    result.append(name);
    result.append(" price:");
    result.append(std::to_string(getRealPrice()));

    return result;
}