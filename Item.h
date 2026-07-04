#pragma once

#include <string>
#include <iostream>
#include <utility>

enum class ItemType {
    Item,
    Weapon,
    Potion,
    Armor,
    Everything
};

class Item 
{
    private:
        std::string name_;

    protected:
        ItemType itemType_;

    public:
        explicit Item (std::string name = "Nothing");
        virtual void PrintInfo() const;
        const std::string& GetName() const;
        ItemType GetItemType() const;
        virtual ~Item () = default;
};