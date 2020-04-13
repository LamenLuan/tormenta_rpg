#include "../../headers/hero.hpp"

#ifndef TORMENTA_RANGER_HPP
#define TORMENTA_RANGER_HPP

class Ranger : public Hero
{
private:
    
public:
    Ranger();
    Ranger(std::string t_name, uint8_t t_strength, uint8_t t_dexterity,
    uint8_t t_constitution, uint8_t t_inteligence, uint8_t t_wisdom,
    uint8_t t_charisma, uint8_t t_level, unsigned short t_maxLife,
    Race t_race, int t_coins);
    
    virtual ~Ranger();
};

#endif