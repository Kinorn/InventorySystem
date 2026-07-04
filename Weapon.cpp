#include "Weapon.h"

Weapon::Weapon (std::string name, int damage)
        : Item(std::move(name)), damage_(damage) 
        { itemType_ = ItemType::Weapon; }

void Weapon::PrintInfo() const
{
        std::cout<<"Weapon: "<<GetName()<<" || Damage: "<<damage_;
}

int Weapon::GetDamage() const {return damage_;}