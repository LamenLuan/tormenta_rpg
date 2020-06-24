#include <iostream>

#include "magicalItem.hpp"

#ifndef TORMENTA_DEFENCE_ITEM_HPP
#define TORMENTA_DEFENCE_ITEM_HPP

class DefenceItem : public virtual MagicalItem
{
private:
    uint8_t m_armorClassBonus{0};
    uint8_t m_armorPenalty{0};

public:
    DefenceItem(int8_t t_armorClassBonus, int8_t t_armorPenalty);
    DefenceItem
    (
        std::string t_name, unsigned int t_price, float t_weight,
        uint8_t t_magicalLevel, uint8_t t_armorClassBonus,
        uint8_t t_armorPenalty
    );
    virtual ~DefenceItem();

    unsigned short get_armorClassBonus() const;
    unsigned short get_armorPenalty() const;
    
    void set_armorClassBonus(uint8_t t_armorClassBonus);
    void set_armorPenalty(uint8_t t_armorPenalty);

    short totalArmorClassBonus() const;

    std::string defenceItemInfo() const;
    std::string defenceItemId() const;
    std::string getIdAsString() const = 0;
};

#endif