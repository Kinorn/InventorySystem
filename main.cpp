#include "InputUtility.h"
#include "Player.h"
#include <iostream>

void PrintMenu();
bool InputTaking();

Player player;

int main()
{
    PrintMenu();

    while (InputTaking())
    {
        PrintMenu();
    }

    return 0;
}

void PrintMenu()
{
    std::cout<<"=== Inventory ===\n\n";

    std::cout<<"1. Show inventory\n";
    std::cout<<"2. Pick up item\n";
    std::cout<<"3. Equip weapon\n";
    std::cout<<"4. Drink potion\n";
    std::cout<<"5. Drop item\n";
    std::cout<<"6. Exit\n\n";
    
}

bool InputTaking()
{
    int command;

    std::cout<<"Enter the command: ";

    if(std::cin>>command)
    {

        switch (command)
        {
        case 1:
            player.PrintInventory();
            return true;

        case 2:
            player.AddToInventory(std::make_unique<Item>("Some Item"));
            return true;

        case 3:
            player.EquipWeapon();
            return true;

        case 4:
            player.DrinkPotion();
            return true;

        case 5: 
            player.DropItem();
            return true;

        case 6:
            return false;
        
        default:
            std::cerr<<"Invalid command\n\n";
            std::cout<<"Please try again\n";
            InputUtility::ClearInput();
            return true;
        }

    } else {

        std::cerr<<"Invalid value\n\n";
        InputUtility::ClearInput();
        return true;
    }

    return false;
}