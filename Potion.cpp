#include "Potion.h"

Potion::Potion (PotionType potionType, float intensity)
        : potionType_ (potionType), intensity_(intensity),
         Item(std::move(
                DefinePotion(potionType))) 
                { itemType_ = ItemType::Potion; }

std::string Potion::DefinePotion(const PotionType potionType) const
{
    switch (potionType)
    {
        case PotionType::Heal:
            return "Heal Potion";

        case PotionType::Poison:
            return "Poison";

        case PotionType::IncreaseDamage:
            return "Increase Damage Potion";

        case PotionType::Water:
        default:
            return "Water";
    }
}

void Potion::PrintInfo() const 
{
    std::cout<<"Potion: "<<GetName()<<" || Intensity of Potion: "<<intensity_;
}

PotionType Potion::GetPotionType() const { return potionType_;}

float Potion::GetIntensity() const {return intensity_;}