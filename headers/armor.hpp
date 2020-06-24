#include "magicalItem.hpp"
#include "defenceItem.hpp"
#include "../headers/enum-types/armorType.hpp"

#ifndef TORMENTA_ARMOR_HPP
#define TORMENTA_ARMOR_HPP

class Armor : public DefenceItem
{
private:
    uint8_t m_maximumDexterity{0};
    ArmorType m_armorType{ArmorType::LIGHT};

public:

    // Constructor to no-magical armors.
    Armor
    (
        std::string t_name, unsigned int t_price, float t_weight,
        uint8_t t_armorClassBonus, uint8_t t_armorPenalty,
        uint8_t t_maximumDexterity, ArmorType t_armorType
    );

    Armor
    (
        std::string t_name, unsigned int t_price, float t_weight,
        uint8_t t_magicalLevel, uint8_t t_armorClassBonus,
        uint8_t t_armorPenalty, uint8_t t_maximumDexterity,
        ArmorType t_armorType
    );
    ~Armor();

    unsigned short get_maximumDexterity() const;
    ArmorType get_armorType() const;

    void set_maximumDexterity(uint8_t t_maximumDexterity);
    void set_armorType(ArmorType t_armorType);

    std::string showArmorType() const;
    std::string armorInfo() const;
    std::string showArmor() const;
    std::string show() const;
    std::string getIdAsString() const;
};

#endif // TORMENTA_ARMOR_HPP