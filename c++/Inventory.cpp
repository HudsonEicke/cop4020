//Defines all of the Inventory class functions
#include "Inventory.h"
#include <fstream>
#include <iostream>
#include <sstream>

//Constructor for Inventory class that passes fname to readData fname is the name of a file
Inventory::Inventory(std::string fname)
{
    readData(fname);
}

//Destructor for Inventory class that does nothing
Inventory::~Inventory()
{

}

//Reads all book data out of file provided by fname and converts it to Book or SpellBook classes based on if first character is b or s if fname is not a valid file prints error message and exits
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

//Adds the provided Book to the vector book is a unique pointer to a Book
void Inventory::add(std::unique_ptr<Book> book)
{
    vec->push_back(move(book));
}

//Returns true if the vector is empty and false otherwhise
bool Inventory::isEmpty()
{
    return vec->empty();
}

//Returns a string of all books concatenated together seperated by newlines book strings are created using polymorphism and calling the str function
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

//Returns the real price total of all books summed together this is done using polymorphism and calling the getRealPrice function
double Inventory::getRealTotal()
{
    double total = 0;

    for(size_t i = 0; i < vec->size(); i++)
    {
        total += vec->at(i)->getRealPrice();
    }

    return total;
}

//Displays all books containing the bname in their name if no books are found displays No result found bname is a string of a book name to be searched
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

//Menu function for the program that exits if no books were loaded otherwise allows users to choose to either search for a book, display all books, display the total price of all books combined, or exit using done if option is invalid displays error message
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
            std::cout << "Total price of the books is " << std::to_string(getRealTotal()) << std::endl;
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