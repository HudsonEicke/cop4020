//File for setting up program run
#include <iostream>
#include "Inventory.h"

//Main function takes user input for file name then creates inventory class and then calls menu function
int main()
{
    std::string input;

    std::cout << "Enter filename" << std::endl;
    std::cin >> input;

    std::unique_ptr<Inventory> inventory = std::make_unique<Inventory>(input);

    inventory->menu();

    return 0;
}