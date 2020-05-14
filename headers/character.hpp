#include <functional>

#include "sheet.hpp"
#include "./enum-types/race.hpp"

#ifndef TORMENTA_CHARACTER_HPP
#define TORMENTA_CHARACTER_HPP

class Character : public Sheet
{
protected:
    Race m_race{Race::HUMAN};
    Backpack m_backpack;
    std::unique_ptr<Weapon> m_equippedWeapon{nullptr};
    std::unique_ptr<Armor> m_equippedArmor{nullptr};
    std::unique_ptr<Shield> m_equippedShield{nullptr};
    unsigned int m_coins{0};

public:

    Character
    (
        std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
        uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
        uint8_t t_charisma, uint8_t t_level, unsigned short t_maxLife,
        Race t_race, unsigned int t_coins, unsigned short t_currentLife = 0u
    );
    virtual ~Character();

    Race get_race() const;
    Backpack& get_backpack();
    Weapon& get_equippedWeapon();
    Armor& get_equippedArmor();
    Shield& get_equippedShield();
    unsigned int get_coins() const;

    // Overriding to update backpack capacity.
    void set_strength(short t_strength);
    
    void set_race(Race t_race);
    void set_backpack(const Backpack& t_backpack);
    void set_equippedWeapon(const Weapon& t_equippedWeapon);
    void set_equippedArmor(const Armor& t_armor);
    void set_equippedShield(const Shield& t_shield);
    void set_coins(unsigned int t_coins);
    
    int dexterity() const;
    int armorClass() const;
    int initiativeBonus() const;
    void naturalWeapon();

    std::string raceName() const;
    std::string show() const;

    virtual std::string getIdAsString() const;
};

#endif // TORMENTA_CHARACTER_HPP