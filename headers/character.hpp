#include "sheet.hpp"
#include "./enum-types/race.hpp"
#include "./exception-types/nullObject.hpp"

#ifndef TORMENTA_CHARACTER_HPP
#define TORMENTA_CHARACTER_HPP

class Character : public Sheet
{
protected:
    Race m_race{Race::HUMAN};
    Backpack m_backpack;
    std::unique_ptr<Weapon> m_equipedWeapon{nullptr};
    std::unique_ptr<Armor> m_equipedArmor{nullptr};
    std::unique_ptr<Shield> m_equipedShield{nullptr};
    unsigned int m_coins{0};

public:
    Character();
    Character(std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
        uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
        uint8_t t_charisma, uint8_t t_level, unsigned short t_maxLife,
        Race t_race, int t_coins);
    virtual ~Character();

    Race get_race() const;
    Backpack& get_backpack();
    // The idea here is to return object, or return exception if null.
    Weapon& get_equipedWeapon();
    Armor get_equipedArmor();
    Shield get_equipedShield();
    unsigned int get_coins() const;

    // Overriding to update backpack capacity.
    void set_strength(short t_strength);
    
    void set_race(Race t_race);
    void set_backpack(Backpack& t_backpack);
    void set_equipedWeapon(Weapon& t_equipedWeapon);
    void set_equipedArmor(Armor& t_armor);
    void set_equipedShield(Shield& t_shield);
    void set_coins(int t_coins);
    
    short dexterity() const;
    short armorClass() const;
    short initiativeBonus() const;
    void naturalWeapon();
    const std::string raceName() const;
    const std::string show() const;
    int equipedWeaponIndex() const;
    std::string getIdAsString() const;
};

#endif // TORMENTA_CHARACTER_HPP