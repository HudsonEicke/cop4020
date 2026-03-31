#include <iostream>
#include "Inventory.h"

int main()
{
    std::string input;

    std::cout << "Enter filename" << std::endl;
    std::cin >> input;

    std::unique_ptr<Inventory> inventory = std::make_unique<Inventory>(input);

    inventory->menu();

    return 0;
}