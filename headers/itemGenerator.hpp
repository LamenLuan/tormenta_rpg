#include "armor.hpp"
#include "shield.hpp"

#ifndef TORMENTA_ITEM_GENERATOR_HPP
#define TORMENTA_ITEM_GENERATOR_HPP

class ItemGenerator
{
private:
    
public:
    static Weapon* generateWeapon(size_t t_index);
};

#endif