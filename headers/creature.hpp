#include "sheet.hpp"
#include "./enum-types/creatureType.hpp"
#include "./enum-types/treasureType.hpp"

#ifndef TORMENTA_MONSTER_HPP
#define TORMENTA_MONSTER_HPP

class Creature : public Sheet
{
private:
    CreatureType m_type{CreatureType::MONSTER};
    int8_t m_armorClass{10u};
    int8_t m_initiative{10u};
    TreasureType m_treasure{TreasureType::NONE};
public:
    Creature();
    Creature(std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
        uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
        uint8_t t_charisma, uint8_t t_level, unsigned short t_maxLife,
        CreatureType t_type, int8_t t_armorClass, TreasureType t_treasure);
    virtual ~Creature();

    CreatureType get_type() const;
    short get_armorClass() const;
    short get_initiative() const;
    TreasureType get_treasure() const;

    void set_type(CreatureType t_type);
    void set_armorClass(int8_t t_armorClass);
    void set_initiative(int8_t t_initiative);
    void set_treasure(TreasureType t_treasure);

    short initiativeBonus() const;
    short armorClass() const;
    const std::string typeName() const;
    const std::string show() const;
};

#endif // TORMENTA_MONSTER_HPP