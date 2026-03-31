//Inventory.h
#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include <memory>
#include <vector>
#include "Book.h"
#include "SpellBook.h"
class Inventory
{
    private:
        std::unique_ptr<std::vector<std::unique_ptr<Book>>> vec = std::make_unique<std::vector<std::unique_ptr<Book>>>();
    public:
        Inventory(std::string fname);

        ~Inventory();

        void readData(std::string fname);
        void add(std::unique_ptr<Book> book);
        bool isEmpty();
        std::string str();
        double getRealTotal();
        void searchBook(std::string bname);
        void menu();
};
#endif //INVENTORY_H