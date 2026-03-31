//Declares the SpellBook child class that inherits from the Book class also defines the instance variables
#ifndef SPELLBOOK_H
#define SPELLBOOK_H
#include "Book.h"
class SpellBook : public Book
{
    private:
        bool canTalk;
    public:
        //Default constructor for SpellBook class sets canTalk = true also calls parent Book class default constructor
        SpellBook();
        //Constructor for SpellBook class that uses gname and gprice parameters to set name and price by calling parent constructor also sets canTalk to cantalkparam btitle is the title of the book and gprice is the price of the book cantalkparam is if the book can talk or not
        SpellBook(std::string gname, double gprice, bool cantalkparam);
        //Constructor for SpellBook class that uses a spellbook line and splits it to set name and price correctly along with the second to last character being 1 or 0 based on if it can talk or not line is a spellbook line in the format s somebooktitle someprice cantalkvalue
        SpellBook(std::string line);

        //Destructor for SpellBook class that does nothing
        virtual ~SpellBook();

        //Returns the value of can talk to the caller
        bool getCanTalk();

        //Overides the virtual getRealPrice method and gets the real price of the spellbook by multiplying the price of the spellbook by 1.1 if it can talk otherwise just the returns the price
        double getRealPrice() override;
        //Overides the virtual str method and returns a string for the spell book in the format Spell Book:<name>  price:<realPrice> if the book can't talk and Speaking Book:<name>  price:<realPrice> if it can
        std::string str() override;
};
#endif