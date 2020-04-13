#ifndef TORMENTA_SHIELD_HPP
#define TORMENTA_SHIELD_HPP

#include "weapon.hpp"

class Shield : public Weapon
{
private:
    int8_t m_armorClassBonus{0};
    int8_t m_armorPenalty{0};

public:
    Shield();
    Shield(std::string t_name, unsigned int t_price, float t_weight,
        unsigned short t_quantity, Dice t_dice, uint8_t t_minimumCriticalDice,
        uint8_t t_criticalMultiplier, DamageType t_type,
        int8_t t_armorClassBonus, int8_t t_armorPenalty);
    virtual ~Shield();

    short get_armorClassBonus() const;
    short get_armorPenalty() const;

    void set_armorClassBonus(int8_t t_armorClassBonus);
    void set_armorPenalty(int8_t t_armorPenalty);

    const std::string shieldInfo() const;
    const std::string showShield() const;
    const std::string show() const;
    std::string shieldId() const;
    std::string getIdAsString() const;
};

#endif //TORMENTA_SHIELD_HPP
