#include <iostream>

#include "magicalItem.hpp"

#ifndef TORMENTA_DEFENCE_ITEM_HPP
#define TORMENTA_DEFENCE_ITEM_HPP

class DefenceItem : public virtual MagicalItem
{
private:
    int8_t m_armorClassBonus{0};
    int8_t m_armorPenalty{0};

public:
    DefenceItem(int8_t t_armorClassBonus, int8_t t_armorPenalty);
    DefenceItem
    (
        std::string t_name, unsigned int t_price, float t_weight,
        uint8_t t_magicalLevel, int8_t t_armorClassBonus, int8_t t_armorPenalty
    );
    virtual ~DefenceItem();

    short get_armorClassBonus() const;
    short get_armorPenalty() const;
    
    void set_armorClassBonus(int8_t t_armorClassBonus);
    void set_armorPenalty(int8_t t_armorPenalty);

    short totalArmorClassBonus() const;

    std::string defenceItemInfo() const;
    std::string defenceItemId() const;
    std::string getIdAsString() const = 0;
};

#endif