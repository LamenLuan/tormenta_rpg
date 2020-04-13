#include "warrior.hpp"

Warrior::Warrior() : Hero()
{
}

Warrior::Warrior(std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
    uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
    uint8_t t_charisma, uint8_t t_level, unsigned short t_maxLife,
    Race t_race, int t_coins)
    :
    Hero(t_name, t_strength, t_dexterity, t_constitution, t_inteligence,
        t_wisdom, t_charisma, t_level, t_maxLife, t_race, t_coins)
{
}

Warrior::~Warrior()
{
}
