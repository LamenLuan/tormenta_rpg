#include "item.hpp"
#include "rollSet.hpp"
#include "./enum-types/damageType.hpp"

#ifndef TORMENTA_WEAPON_H
#define TORMENTA_WEAPON_H

class Weapon : public Item
{

protected:
    RollSet m_damage;
    uint8_t m_minCriticalDice{20u};
    uint8_t m_criticalMultiplier{2u};
    DamageType m_damageType{DamageType::BLUDGEON};

public:
    Weapon();
    Weapon(std::string t_name, unsigned int t_price, float t_weight,
        unsigned short t_quantity, Dice t_dice, uint8_t t_minimumCriticalDice,
        uint8_t t_criticalMultiplier, DamageType t_type);
    virtual ~Weapon();

    RollSet& get_damage();
    DamageType get_damageType() const;
    int get_minCriticalDice() const;
    int get_criticalMultiplier() const;

    void set_damage(const RollSet& t_damage);
    void set_damageType(DamageType t_type);
    void set_minCriticalDice(uint8_t t_minCriticalDice);
    void set_criticalMultiplier(uint8_t t_criticalMultiplier);

    std::string showWeaponType() const;
    std::string weaponInfo() const;
    std::string showWeapon() const;
    std::string show() const;
    std::string weaponId() const;
    std::string getIdAsString() const;
};

#endif// TORMENTA_WEAPON_HPP