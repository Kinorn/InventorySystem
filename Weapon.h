#pragma once

#include "Item.h"

class Weapon : public Item {
    private:
        int damage_;

    public:
        explicit Weapon(std::string name, int damage = 0);
        void PrintInfo() const override;
        int GetDamage() const;
};