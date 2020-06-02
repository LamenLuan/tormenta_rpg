#include "item.hpp"

#ifndef TORMENTA_EQUIPABLE_ITEM_HPP
#define TORMENTA_EQUIPABLE_ITEM_HPP

class EquipableItem : public Item
{
private:
    uint8_t m_magicLevel{0};

public:
    EquipableItem
    (
        std::string t_name, unsigned int t_price, float t_weight,
        uint8_t t_magicLevel
    );
    virtual ~EquipableItem();

    void set_magicLevel(uint8_t t_magicLevel);
    unsigned short get_magicLevel() const;

    std::string showName() const;
    std::string equipableItemId() const;
    std::string getIdAsString() const = 0;
};

#endif // TORMENTA_EQUIPABLE_ITEM_HPP