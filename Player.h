#pragma once

#include "Armor.h"
#include "Potion.h"
#include "Weapon.h"
#include "InputUtility.h"
#include <vector>
#include <memory>
#include <iostream>

class Player 
{
    private:

        // Player Data ----------------
        std::vector<std::unique_ptr<Item>> inventory_;
        int health_;
        size_t equippedWeapon_ {0};
        float reinforceDamage {0.0f};

        // Supplementary Functions ----

        void PrintItem (const size_t index) const;
        size_t PickItem(const std::vector<size_t>& indices);
        void UsePotion(size_t index);

        // Function stats -------------
        void ClearFunctionState() const;
        mutable bool selectionInProgress {true};
        mutable bool cancelRequested {false};

    public:
        explicit Player (int health = 100);

        std::vector<size_t> PrintInventory (ItemType filter) const;
        void PrintInventory () const;

        void AddToInventory (std::unique_ptr<Item> item);
        void EquipWeapon ();
        void DrinkPotion ();
        void DropItem ();

};