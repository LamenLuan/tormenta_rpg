#include "item.hpp"

#ifndef TORMENTA_ARMOR_HPP
#define TORMENTA_ARMOR_HPP

class Armor : public Item
{
private:
    int8_t m_armorClassBonus{0};
    int8_t m_armorPenalty{0};
    int8_t m_maximumDexterity{0};

public:
    Armor();
    Armor(std::string t_name, unsigned int t_price, float t_weight,
        int8_t t_armorClassBonus, int8_t t_armorPenalty,
        int8_t t_maximumDexterity);
    ~Armor();

    short get_armorClassBonus() const;
    short get_armorPenalty() const;
    short get_maximumDexterity() const;

    void set_armorClassBonus(int8_t t_armorClassBonus);
    void set_armorPenalty(int8_t t_armorPenalty);
    void set_maximumDexterity(int8_t t_maximumDexterity);

    const std::string armorInfo() const;
    const std::string showArmor() const;
    const std::string show() const;
    std::string armorId() const;
    std::string getIdAsString() const;
};

#endif // TORMENTA_ARMOR_HPP