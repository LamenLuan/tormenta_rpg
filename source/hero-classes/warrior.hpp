#include "../../headers/hero.hpp"

#ifndef TORMENTA_WARRIOR_HPP
#define TORMENTA_WARRIOR_HPP

class Warrior : public Hero
{
private:
    
public:
    Warrior();
    Warrior(std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
    uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
    uint8_t t_charisma, uint8_t t_level, Race t_race, int t_coins,
    unsigned short currentLife = 0u, unsigned int currentExp = 0u);
    
    virtual ~Warrior();

    std::string getIdAsString() const;
};

#endif