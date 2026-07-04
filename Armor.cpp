#include "Armor.h"

Armor::Armor (std::string name, float protectionPercent)
        : Item(std::move(name)), protectionPercent_(protectionPercent)
        { itemType_ = ItemType::Armor; }

void Armor::PrintInfo() const 
{
        std::cout<<"Armor: "<<GetName()<<" || Percent of Protection: "<<protectionPercent_;
}

float Armor::GetProtectionPercent() const {return protectionPercent_;}