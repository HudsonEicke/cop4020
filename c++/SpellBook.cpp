#include "SpellBook.h"
#include <iostream>
#include <sstream>

SpellBook::SpellBook() : Book()
{
    this->canTalk = true;
}

SpellBook::SpellBook(std::string gname, double gprice, bool cantalkparam) : Book(gname, gprice)
{
    this->canTalk = cantalkparam;
}

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

SpellBook::~SpellBook()
{
    
}

bool SpellBook::getCanTalk()
{
    return canTalk;
}

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