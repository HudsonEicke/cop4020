//Defines all of the SpellBook child class functions
#include "SpellBook.h"
#include <iostream>
#include <sstream>

//Default constructor for SpellBook class sets canTalk = true also calls parent Book class default constructor
SpellBook::SpellBook() : Book()
{
    this->canTalk = true;
}

//Constructor for SpellBook class that uses gname and gprice parameters to set name and price by calling parent constructor also sets canTalk to cantalkparam btitle is the title of the book and gprice is the price of the book cantalkparam is if the book can talk or not
SpellBook::SpellBook(std::string gname, double gprice, bool cantalkparam) : Book(gname, gprice)
{
    this->canTalk = cantalkparam;
}

//Constructor for SpellBook class that uses a spellbook line and splits it to set name and price correctly along with the second to last character being 1 or 0 based on if it can talk or not line is a spellbook line in the format s somebooktitle someprice cantalkvalue
SpellBook::SpellBook(std::string line) : Book(line)
{
    if(line[line.length() - 2] == '1')
    {
        this->canTalk = true;
    }
    else
    {
        this->canTalk = false;
    }
}

//Destructor for SpellBook class that does nothing
SpellBook::~SpellBook()
{
    
}

//Returns the value of can talk to the caller
bool SpellBook::getCanTalk()
{
    return canTalk;
}

//Overides the virtual getRealPrice method and gets the real price of the spellbook by multiplying the price of the spellbook by 1.1 if it can talk otherwise just the returns the price
double SpellBook::getRealPrice()
{
    if(canTalk)
    {
        return getPrice() * 1.1;
    }
    else
    {
        return getPrice();
    }
}

//Overides the virtual str method and returns a string for the spell book in the format Spell Book:<name>  price:<realPrice> if the book can't talk and Speaking Book:<name>  price:<realPrice> if it can
std::string SpellBook::str()
{
    std::string result;

    if(canTalk)
    {
        result = "Speaking Book:";
    }
    else
    {
        result = "Spell Book:";
    }

    result.append(getName());
    result.append(" price:");
    result.append(std::to_string(getRealPrice()));

    return result;
}