//SpellBook.h
#ifndef SPELLBOOK_H
#define SPELLBOOK_H
#include "Book.h"
class SpellBook : public Book
{
    private:
        bool canTalk;
    public:
        SpellBook();
        SpellBook(std::string gname, double gprice, bool cantalkparam);
        SpellBook(std::string line);

        ~SpellBook();

        bool getCanTalk();

        double getRealPrice() override;
        std::string str() override;
};

#endif //SPELLBOOK_H