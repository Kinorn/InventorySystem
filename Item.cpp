#include "Item.h"

Item::Item (std::string name)
    : name_(std::move(name)), itemType_(ItemType::Item) {}

void Item::PrintInfo() const 
{
    std::cout<<"Item: "<<name_;
}

const std::string& Item::GetName() const { return name_;}

ItemType Item::GetItemType() const { return itemType_;}