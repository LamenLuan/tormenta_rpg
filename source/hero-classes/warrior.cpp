#include "warrior.hpp"

#include <utility>

Warrior::Warrior() : Hero()
{
}

Warrior::Warrior(std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
    uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
    uint8_t t_charisma, uint8_t t_level, Race t_race, int t_coins,
    unsigned short currentLife, unsigned int currentExp)
    :
    Hero(std::move(t_name), t_strength, t_dexterity, t_constitution, t_inteligence,
        t_wisdom, t_charisma, t_level, 5u, t_race, t_coins, currentLife,
        currentExp)
{
}

Warrior::~Warrior() = default;

std::string Warrior::getIdAsString() const
{
    std::stringstream stream;

    stream << "G " << Hero::getIdAsString();

    return stream.str();
}