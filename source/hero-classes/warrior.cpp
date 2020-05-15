#include "warrior.hpp"

#include <utility>

Warrior::Warrior
(
    std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
    uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
    uint8_t t_charisma, Race t_race
)
:
    Hero
    (
        t_name, t_strength, t_dexterity, t_constitution, t_inteligence,
        t_wisdom, t_charisma, 5u, t_race
    )
{
}

Warrior::Warrior
(
    std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
    uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
    uint8_t t_charisma, Race t_race, unsigned short t_maxLife,
    unsigned short t_currentLife, unsigned int t_currentExp
)
:
    Hero
    (
        std::move(t_name), t_strength, t_dexterity, t_constitution,
        t_inteligence, t_wisdom, t_charisma, 5u, t_race, t_maxLife,
        t_currentLife, t_currentExp
    )
{
}

Warrior::~Warrior() = default;

std::string Warrior::show() const
{
    std::stringstream stream;

    stream
        << "Name: " << m_name << '\n'
        << "Race: " << raceName() << '\n'
        << "Class: Warrior" << "\n\n"
        << Hero::show();

    return stream.str();
}

std::string Warrior::getIdAsString() const
{
    std::stringstream stream;

    stream << "G " << Hero::getIdAsString();

    return stream.str();
}