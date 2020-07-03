#include "armor.hpp"
#include "shield.hpp"

#ifndef TORMENTA_ITEM_GENERATOR_HPP
#define TORMENTA_ITEM_GENERATOR_HPP

class ItemGenerator
{
private:
    
public:
    static const uint8_t weaponQuantity{18};
    static const uint8_t armorQuantity{12};
    static const uint8_t shieldQuantity{2};

    static Item* generateWeapon(size_t t_index);
    static Item* generateArmor(size_t t_index);
    static Item* generateShield(size_t t_index);

    static Item* generateDefenceItem(size_t t_index);

    static Item* generateItem(size_t t_index);
};

#endif