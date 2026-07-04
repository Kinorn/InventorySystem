#pragma once

#include "Item.h"

class Armor : public Item 
{
    private: 
        float protectionPercent_;

    public:
        explicit Armor (std::string name = "Nothing", float protectionPercent = 0.0f);
        void PrintInfo() const override;
        float GetProtectionPercent () const;
};