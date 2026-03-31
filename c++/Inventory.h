//Declares the Inventory class and defines the instance variables along with intializing the vector
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
        //Constructor for Inventory class that passes fname to readData fname is the name of a file
        Inventory(std::string fname);

        //Destructor for Inventory class that does nothing
        virtual ~Inventory();

        //Reads all book data out of file provided by fname and converts it to Book or SpellBook classes based on if first character is b or s if fname is not a valid file prints error message and exits
        void readData(std::string fname);
        //Adds the provided Book to the vector book is a unique pointer to a Book
        void add(std::unique_ptr<Book> book);
        //Returns true if the vector is empty and false otherwhise
        bool isEmpty();
        //Returns a string of all books concatenated together seperated by newlines book strings are created using polymorphism and calling the str function
        std::string str();
        //Returns the real price total of all books summed together this is done using polymorphism and calling the getRealPrice function
        double getRealTotal();
        //Displays all books containing the bname in their name if no books are found displays No result found bname is a string of a book name to be searched
        void searchBook(std::string bname);
        //Menu function for the program that exits if no books were loaded otherwise allows users to choose to either search for a book, display all books, display the total price of all books combined, or exit using done if option is invalid displays error message
        void menu();
};
#endif