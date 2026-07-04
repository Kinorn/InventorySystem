#include "Player.h"

Player::Player (int health)
    : health_(health) 
    {
        inventory_.emplace_back(std::make_unique<Weapon>("Sword", 10));
    }

// 1. Print Inventory <----------------------------------------------------

std::vector<size_t> Player::PrintInventory( ItemType filter ) const
{
    InputUtility::PrintSeparation();

    int count {0};
    std::vector<size_t> indices;

    if (!inventory_.empty())
    {
        for (size_t i{0}; i < inventory_.size(); i++)
        {
            if(inventory_[i]->GetItemType() == filter || filter == ItemType::Everything)
            {
                std::cout<<(count += 1)<<". ";

                PrintItem(i);

                indices.push_back(i);

                std::cout<<'\n';
            }
        }
        if(!indices.empty())
        {
            std::cout<<indices.size() + 1 <<". Cancel\n\n";
        }

    } else {
        cancelRequested = true;
        std::cerr<<"Inventory is empty!\n\n";

        InputUtility::WaitForEnter();
        InputUtility::PrintSeparation();
    }

    return indices;
}

// Overload -------------------

void Player::PrintInventory() const 
{

    InputUtility::PrintSeparation();

    int count {0};

    if (!inventory_.empty())
    {
        for (size_t i{0}; i < inventory_.size(); i++)
        {

            std::cout<<(count += 1)<<". ";

            PrintItem(i);

            std::cout<<'\n';

        }

    } else {
        std::cerr<<"Inventory is empty!\n";
    }

    std::cout<<'\n';

    InputUtility::WaitForEnter();

    InputUtility::PrintSeparation();
}

void Player::PrintItem (const size_t index) const 
{

    inventory_[index]->PrintInfo();

    if(inventory_[index]->GetItemType() == ItemType::Weapon 
                        && index == equippedWeapon_)
    {
        std::cout<<" <---- Equipped Weapon";
    }

    std::cout<<'\n';
}

// 2. Adding to Inventory <---------------------------------------------------

void Player::AddToInventory (std::unique_ptr<Item> item)
{

    InputUtility::PrintSeparation();

    inventory_.emplace_back(std::move(item));
    std::cout<<inventory_.back()->GetName()<<" was added to inventory!\n\n";

    InputUtility::WaitForEnter();

    InputUtility::PrintSeparation();
}

// 3. Equiping Weapon <--------------------------------------------------------

void Player::EquipWeapon () 
{
    ClearFunctionState();

    InputUtility::PrintSeparation();

    auto weaponIndex = PrintInventory(ItemType::Weapon);

    if (!cancelRequested)
    {
        
        if(!weaponIndex.empty())
        {
            std::cout<<"Pick weapon to change to it: ";

            while(selectionInProgress)
            {
                size_t index = PickItem(weaponIndex);

                if(!selectionInProgress)
                {
                    equippedWeapon_ = index;
                } else if (cancelRequested)
                {
                    return;
                }
            }

            std::cout<<"You changed weapon to "
                    <<inventory_[equippedWeapon_]->GetName()<<"!\n";

        } else {
            std::cout<<"There are no weapon in the inventory!\n";
        }

        std::cout<<'\n';

        InputUtility::WaitForEnter();    

        InputUtility::PrintSeparation();
    }  
}

// 4. Drink Potion <-----------------------------------------------------

void Player::DrinkPotion ()
{
    ClearFunctionState();

    InputUtility::PrintSeparation();

    auto potionIndices = PrintInventory(ItemType::Potion);
    
    if(!cancelRequested)
    {
        if(!potionIndices.empty())
        {
            std::cout<<"Pick potion to drink: ";

            while(selectionInProgress)
            {
                size_t index = PickItem(potionIndices);
                if(!selectionInProgress)
                {
                    UsePotion(index);
                } else if (cancelRequested)
                {
                    return;
                }
            }
        } else {
            std::cout<<"There are no potions in the inventory!\n";
        }

        std::cout<<'\n';

        InputUtility::WaitForEnter();

        InputUtility::PrintSeparation();
    }
}

// 5. Drop Item <------------------------------------------------------------

void Player::DropItem ()
{
    ClearFunctionState();

    InputUtility::PrintSeparation();

    auto indices = PrintInventory(ItemType::Everything);

    if(!cancelRequested)
    {
        std::cout<<"Pick item to drop: ";

        while(selectionInProgress)
        {
            size_t index = PickItem(indices);
            if(!selectionInProgress)
            {
                std::cout<<inventory_[index]->GetName()<<" was removed from the inventory.\n";
                inventory_.erase(inventory_.begin() + index);

                InputUtility::WaitForEnter();
                InputUtility::PrintSeparation();
                
            } else if (cancelRequested)
            {
                InputUtility::PrintSeparation();
                return;
            }
        }
    }
}

// Supplementary Functions <-------------------------------------------------------------------

void Player::ClearFunctionState() const 
{
    selectionInProgress = true;
    cancelRequested = false;
}

size_t Player::PickItem(const std::vector<size_t>& indices)
{
    int pick;

    if(std::cin>>pick)
    {
        if (pick == indices.size() + 1)
        {
            cancelRequested = true;
            return 0;
        }
        for(size_t i{0}; i < indices.size(); i++)
        {
            if(i+1 == pick){
                selectionInProgress = false;
                return indices[i];
            }
        }

        std::cerr<<"Invalid Command\n\n";
    }
     else 
    {
        std::cerr<<"Invalid Value\n\n";
    }

    std::cout<<"Please try again: ";
    InputUtility::ClearInput();
    selectionInProgress = true;

    return 0;
}

void Player::UsePotion( size_t index )
{
    auto* ptr = static_cast<Potion*>(inventory_[index].get());

    switch( ptr->GetPotionType() )
    {
        case PotionType::Heal: 
        {
            int increment = static_cast<int> ( health_ * ptr->GetIntensity() );

            health_ += increment;

            std::cout<<"You healed "<<increment<<" health points!\n";
            std::cout<<"Current health: "<<health_<<'\n';
            break;
        }

        case PotionType::IncreaseDamage:
        {
            reinforceDamage += ptr->GetIntensity();

            std::cout<<ptr->GetIntensity() * 100<<"% increase in weapon damage!\n";

            std::cout<<"Current damage of equipped weapon: "
                <<static_cast<Weapon*>(inventory_[equippedWeapon_].get())
                ->GetDamage() * reinforceDamage<<'\n';

            break;
        }

        case PotionType::Poison:
        {
            int decrement = static_cast<int> (health_ * ptr->GetIntensity() );
            health_ -= decrement;

            std::cout<<"You are poisoned!\n";
            std::cout<<"You lost "<<decrement<<" health points!\n";
            std::cout<<"Current health: "<<health_<<'\n';
            break;
        }

        default:
            std::cout<<"It has no effect on you.\n";
    }

    inventory_.erase(inventory_.begin() + index);
}