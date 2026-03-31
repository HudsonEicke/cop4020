#include "Inventory.h"
#include <fstream>
#include <iostream>
#include <sstream>

Inventory::Inventory(std::string fname)
{
    readData(fname);
}

Inventory::~Inventory()
{

}

void Inventory::readData(std::string fname)
{
    std::ifstream inputFile(fname);

    if(inputFile.is_open())
    {
        std::string line;
        while (getline(inputFile, line))
        {
            if(line[0] == 'b')
            {
                std::unique_ptr<Book> newBook(new Book(line));

                add(move(newBook));
            }
            else
            {
                std::unique_ptr<SpellBook> newSpellBook(new SpellBook(line));

                add(move(newSpellBook));
            }
        }

        inputFile.close();
    }
    else
    {
        std::cout << "Error opening file " << fname << std::endl;
    }
}

void Inventory::add(std::unique_ptr<Book> book)
{
    vec->push_back(move(book));
}

bool Inventory::isEmpty()
{
    return vec->empty();
}

std::string Inventory::str()
{
    std::string result = "";

    for(size_t i = 0; i < vec->size(); i++)
    {
        result.append(vec->at(i)->str());
        result.append("\n");
    }

    return result;
}

double Inventory::getRealTotal()
{
    double total = 0;

    for(size_t i = 0; i < vec->size(); i++)
    {
        total += vec->at(i)->getRealPrice();
    }

    return total;
}

void Inventory::searchBook(std::string bname)
{
    bool foundOne = false;

    for(size_t i = 0; i < vec->size(); i++)
    {
        if(vec->at(i)->str().find(bname) != std::string::npos)
        {
            std::cout << vec->at(i)->str() << std::endl;
            foundOne = true;
        }
    }

    if (!foundOne)
    {
        std::cout << "No result found" << std::endl;
    }
}

void Inventory::menu()
{
    if(isEmpty())
    {
        return;
    }
    
    bool notDone = true;
    std::string input;

    do
    {
        std::cout << "Enter option search BOOKNAME/all/total/done" << std::endl;
        std::cin >> input;

        if(input.compare("search") == 0)
        {
            std::cin >> input;
            std::cout << "Searched book name: " << input << std::endl;
            searchBook(input);
        }
        else if(input.compare("all") == 0)
        {
            std::cout << "The book/s in the inventory is/are" << std::endl;
            std::cout << str();
        }
        else if(input.compare("total") == 0)
        {
            std::cout << "Total price of the books is " << getRealTotal() << std::endl;
        }
        else if(input.compare("done") == 0)
        {
            notDone = false;
        }
        else
        {
            std::cout << "Invalid option" << std::endl;
        }

        std::cout << std::endl;
    } while (notDone);
}