#include "magicalItem.hpp"
#include "rollSet.hpp"
#include "./enum-types/damageType.hpp"
#include "./enum-types/weaponType.hpp"

#ifndef TORMENTA_WEAPON_H
#define TORMENTA_WEAPON_H

class Weapon : public virtual MagicalItem
{

protected:
    RollSet m_damage;
    uint8_t m_minCriticalDice{20u};
    uint8_t m_criticalMultiplier{2u};
    DamageType m_damageType{DamageType::BLUDGEON};
    WeaponType m_weaponType{WeaponType::ONE_HANDED};

public:
    Weapon
    (
        unsigned short t_quantity, Dice t_dice, uint8_t t_minimumCriticalDice,
        uint8_t t_criticalMultiplier, DamageType t_Damagetype,
        WeaponType t_weaponType
    );

    // Constructor to no-magical weapons.
    Weapon
    (
        std::string t_name, unsigned int t_price, float t_weight,
        unsigned short t_quantity, Dice t_dice, uint8_t t_minimumCriticalDice,
        uint8_t t_criticalMultiplier, DamageType t_Damagetype,
        WeaponType t_weaponType
    );

    Weapon
    (
        std::string t_name, unsigned int t_price, float t_weight,
        uint8_t t_magicalLevel, unsigned short t_quantity, Dice t_dice,
        uint8_t t_minimumCriticalDice, uint8_t t_criticalMultiplier,
        DamageType t_Damagetype, WeaponType t_weaponType
    );

    virtual ~Weapon();

    RollSet& get_damage();
    unsigned short get_minCriticalDice() const;
    unsigned short get_criticalMultiplier() const;
    DamageType get_damageType() const;
    WeaponType get_weaponType() const;

    void set_damage(const RollSet& t_damage);
    void set_minCriticalDice(uint8_t t_minCriticalDice);
    void set_criticalMultiplier(uint8_t t_criticalMultiplier);
    void set_damageType(DamageType t_damageType);
    void set_weaponType(WeaponType t_weaponType);

    std::string showDamageType() const;
    std::string showWeaponType() const;
    std::string weaponInfo() const;
    std::string showWeapon() const;
    std::string show() const;
    std::string weaponId() const;
    std::string getIdAsString() const;
};

#endif// TORMENTA_WEAPON_HPP