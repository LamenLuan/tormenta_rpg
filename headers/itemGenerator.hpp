#include "armor.hpp"
#include "shield.hpp"

#ifndef TORMENTA_ITEM_GENERATOR_HPP
#define TORMENTA_ITEM_GENERATOR_HPP

class ItemGenerator
{
private:
    
public:
    static Weapon generateWeapon(size_t t_index);
    static Armor generateArmor(size_t t_index);
    static Shield generateShield(size_t t_index);
};

#endif