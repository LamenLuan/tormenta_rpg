#include "item.hpp"

#ifndef TORMENTA_EQUIPABLE_ITEM_HPP
#define TORMENTA_EQUIPABLE_ITEM_HPP

class MagicalItem : public virtual Item
{
private:
    uint8_t m_magicalLevel{0u};

public:
    MagicalItem();
    MagicalItem(uint8_t t_magicalLevel);
    MagicalItem
    (
        std::string t_name, unsigned int t_price, float t_weight,
        uint8_t t_magicalLevel
    );
    virtual ~MagicalItem();

    void set_magicalLevel(uint8_t t_magicalLevel);
    unsigned short get_magicalLevel() const;

    std::string showName() const;
    std::string magicalItemId() const;
    std::string getIdAsString() const = 0;
};

#endif // TORMENTA_EQUIPABLE_ITEM_HPP