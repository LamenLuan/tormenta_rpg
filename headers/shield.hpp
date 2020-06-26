#ifndef TORMENTA_SHIELD_HPP
#define TORMENTA_SHIELD_HPP

#include "weapon.hpp"
#include "defenceItem.hpp"

class Shield : public DefenceItem, public Weapon
{
private:

public:

    Shield
    (
        std::string t_name, unsigned int t_price, float t_weight,
        uint8_t t_armorClassBonus, uint8_t t_armorPenalty,
        unsigned short t_quantity, Dice t_dice
    );

    // For shields with different critical rate/damage.
    Shield
    (
        std::string t_name, unsigned int t_price, float t_weight,
        uint8_t t_magicalLevel, uint8_t t_armorClassBonus,
        uint8_t t_armorPenalty, unsigned short t_quantity, Dice t_dice,
        uint8_t t_minimumCriticalDice, uint8_t t_criticalMultiplier
    );
    virtual ~Shield();

    std::string showShield() const;
    std::string show() const;
    std::string getIdAsString() const;
};

#endif //TORMENTA_SHIELD_HPPs
