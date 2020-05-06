#include "../headers/creature.hpp"

#include <utility>

Creature::Creature(std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
    uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
    uint8_t t_charisma, uint8_t t_level, unsigned short t_maxLife,
    CreatureType t_type, int8_t t_armorClass, TreasureType t_treasure)
    :
    Sheet(std::move(t_name), t_strength, t_dexterity, t_constitution, t_inteligence,
    t_wisdom, t_charisma, t_level, t_maxLife),
    m_type(t_type), m_armorClass(t_armorClass), m_treasure(t_treasure)
{
}

Creature::~Creature() = default;

CreatureType Creature::get_type() const { return m_type; }

uint8_t Creature::get_armorClass() const { return m_armorClass; }

uint8_t Creature::get_initiative() const { return m_initiative; }

TreasureType Creature::get_treasure() const { return m_treasure; }

void Creature::set_type(CreatureType t_type)
{
    m_type = t_type;
}

void Creature::set_armorClass(int8_t t_armorClass)
{
    m_armorClass = t_armorClass; 
}

void Creature::set_initiative(int8_t t_initiative)
{
    m_initiative = t_initiative; 
}

void Creature::set_treasure(TreasureType t_treasure)
{
    m_treasure = t_treasure;
}

int Creature::initiativeBonus() const
{
    return m_initiative;
}

int Creature::armorClass() const
{
    return m_armorClass;
}

std::string Creature::typeName() const
{
    switch (m_type)
    {
        case CreatureType::ANIMAL : return "Animal";
        case CreatureType::CONSTRUCT : return "Construct";
        case CreatureType::HUMANOID : return "Humanoid";
        case CreatureType::MONSTER : return "Monster";
        case CreatureType::SPIRT : return "Spirit";
        default: return "Undead";
    }
}

std::string Creature::show() const
{
    std::stringstream stream;

    stream
        << "Name: " << m_name << '\n'
        << "Type: " << typeName() << '\n'
        << "Level: " << static_cast<short>(m_level) << '\n'
        << "Life: " << m_currentLife << '/' << m_maxLife << '\n'
        << "Armor class: " << std::showpos << armorClass() << '\n';

    return stream.str();
}