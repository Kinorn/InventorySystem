#pragma once

#include "Item.h"

enum class PotionType 
{
    Heal,
    Poison,
    IncreaseDamage,
    Water,
};

class Potion : public Item 
{
    private:
        PotionType potionType_;
        float intensity_;
        std::string DefinePotion(const PotionType potionType) const;

    public:
        explicit Potion(PotionType potionType = PotionType::Water, float intensity = 0.1f);
        void PrintInfo() const override;
        PotionType GetPotionType () const;
        float GetIntensity () const;
};